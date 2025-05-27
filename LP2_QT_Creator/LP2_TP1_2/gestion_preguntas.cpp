#include "gestion_preguntas.h"
#include "ui_gestion_preguntas.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QFileDialog>
#include <QBuffer>
#include <QImage>
#include <QRegularExpression>

// Constructor de la ventana de gestion de preguntas
GestionPreguntas::GestionPreguntas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionPreguntas),
    model(new QStandardItemModel(this)),
    editingRow(-1) // Indica si se esta editando una fila existente
{
    ui->setupUi(this); // Carga la interfaz

    // Cargar las categorias desde categorias.json al ComboBox
    QFile catFile("categorias.json");
    if (catFile.open(QIODevice::ReadOnly)) {
        QJsonArray catArr = QJsonDocument::fromJson(catFile.readAll()).array();
        for (auto v : catArr) {
            ui->categoriaComboBox->addItem(v.toObject().value("nombre").toString());
        }
        catFile.close();
    }

    // Configurar el modelo con 7 columnas
    model->setColumnCount(7);
    model->setHeaderData(0, Qt::Horizontal, "Texto");
    model->setHeaderData(1, Qt::Horizontal, "Imagen Base64");
    model->setHeaderData(2, Qt::Horizontal, "A");
    model->setHeaderData(3, Qt::Horizontal, "B");
    model->setHeaderData(4, Qt::Horizontal, "C");
    model->setHeaderData(5, Qt::Horizontal, "Correcta");
    model->setHeaderData(6, Qt::Horizontal, "Categoria");

    ui->preguntasTableView->setModel(model); // Asignar el modelo a la tabla

    cargarPreguntasDeJson(); // Cargar preguntas existentes
}

// Destructor
GestionPreguntas::~GestionPreguntas()
{
    delete ui;
}

// Accion cuando se hace clic en el boton para buscar imagen
void GestionPreguntas::on_browseImagePushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Seleccionar imagen", QString(), "Images (*.png *.jpg *.jpeg)");
    if (path.isEmpty())
        return;
    ui->imagenLineEdit->setText(path); // Mostrar ruta en el campo
}

// Accion cuando se crea o guarda una pregunta
void GestionPreguntas::on_crearPushButton_clicked()
{
    if (!validarCampos())
        return;

    // Obtener datos del formulario
    QString texto   = ui->textoTextEdit->toPlainText().trimmed();
    QString rutaImg = ui->imagenLineEdit->text().trimmed();
    QString imgBase64;

    // Convertir imagen a base64 si se selecciono
    if (!rutaImg.isEmpty()) {
        QImage img(rutaImg);
        if (img.isNull()) {
            QMessageBox::warning(this, "Error", "No se pudo cargar la imagen seleccionada.");
        } else {
            QByteArray buf;
            QBuffer buffer(&buf);
            buffer.open(QIODevice::WriteOnly);
            img.save(&buffer, "PNG");
            imgBase64 = QString::fromLatin1(buf.toBase64());
        }
    }

    // Obtener opciones y respuesta correcta
    QString a        = ui->opA_LineEdit->text().trimmed();
    QString b        = ui->opB_LineEdit->text().trimmed();
    QString c        = ui->opC_LineEdit->text().trimmed();
    QString correcta = ui->correctaLineEdit->text().trimmed().toUpper();
    QString cat      = ui->categoriaComboBox->currentText();

    // Si estamos editando una fila existente
    if (editingRow >= 0) {
        model->item(editingRow, 0)->setText(texto);
        model->item(editingRow, 1)->setText(imgBase64);
        model->item(editingRow, 2)->setText(a);
        model->item(editingRow, 3)->setText(b);
        model->item(editingRow, 4)->setText(c);
        model->item(editingRow, 5)->setText(correcta);
        model->item(editingRow, 6)->setText(cat);
        ui->crearPushButton->setText("Crear");
        editingRow = -1;
    } else {
        agregarPreguntaAModelo(texto, imgBase64, a, b, c, correcta, cat);
    }

    guardarPreguntasEnJson(); // Guardar los cambios

    // Limpiar el formulario
    ui->textoTextEdit->clear();
    ui->imagenLineEdit->clear();
    ui->opA_LineEdit->clear();
    ui->opB_LineEdit->clear();
    ui->opC_LineEdit->clear();
    ui->correctaLineEdit->clear();
}

// Recargar categorias y preguntas
void GestionPreguntas::on_listarPreguntasPushButton_clicked()
{
    ui->categoriaComboBox->clear();

    // Cargar categorias desde archivo
    QFile catFile("categorias.json");
    if (catFile.open(QIODevice::ReadOnly)) {
        QJsonArray catArr = QJsonDocument::fromJson(catFile.readAll()).array();
        for (auto v : catArr) {
            ui->categoriaComboBox->addItem(v.toObject().value("nombre").toString());
        }
        catFile.close();
    }

    cargarPreguntasDeJson(); // Volver a cargar las preguntas
}

// Editar una pregunta seleccionada
void GestionPreguntas::on_editarPushButton_clicked()
{
    QModelIndex idx = ui->preguntasTableView->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Error", "Seleccione una pregunta para editar.");
        return;
    }

    editingRow = idx.row();

    // Cargar datos en el formulario
    ui->textoTextEdit->setPlainText(model->item(editingRow, 0)->text());
    ui->imagenLineEdit->setText(model->item(editingRow, 1)->text());
    ui->opA_LineEdit->setText(model->item(editingRow, 2)->text());
    ui->opB_LineEdit->setText(model->item(editingRow, 3)->text());
    ui->opC_LineEdit->setText(model->item(editingRow, 4)->text());
    ui->correctaLineEdit->setText(model->item(editingRow, 5)->text());

    int catIndex = ui->categoriaComboBox->findText(model->item(editingRow, 6)->text());
    if (catIndex >= 0) ui->categoriaComboBox->setCurrentIndex(catIndex);

    ui->crearPushButton->setText("Guardar");
}

// Eliminar una pregunta seleccionada
void GestionPreguntas::on_eliminarPushButton_clicked()
{
    QModelIndex idx = ui->preguntasTableView->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "error", "Seleccione una pregunta para eliminar.");
        return;
    }

    model->removeRow(idx.row()); // Eliminar fila
    guardarPreguntasEnJson(); // Guardar cambios
}

// Cargar preguntas desde el archivo JSON
void GestionPreguntas::cargarPreguntasDeJson()
{
    model->removeRows(0, model->rowCount());

    QFile file("preguntas.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonArray arr = QJsonDocument::fromJson(file.readAll()).array();
    file.close();

    for (auto val : arr) {
        QJsonObject o = val.toObject();
        agregarPreguntaAModelo(
            o.value("texto").toString(),
            o.value("imagen").toString(),
            o.value("opA").toString(),
            o.value("opB").toString(),
            o.value("opC").toString(),
            o.value("correcta").toString(),
            o.value("categoria").toString()
        );
    }
}

// Guardar preguntas actuales en archivo JSON
void GestionPreguntas::guardarPreguntasEnJson()
{
    QJsonArray arr;
    for (int r = 0; r < model->rowCount(); ++r) {
        QJsonObject o;
        o["texto"]    = model->item(r, 0)->text();
        o["imagen"]   = model->item(r, 1)->text();
        o["opA"]      = model->item(r, 2)->text();
        o["opB"]      = model->item(r, 3)->text();
        o["opC"]      = model->item(r, 4)->text();
        o["correcta"] = model->item(r, 5)->text();
        o["categoria"]= model->item(r, 6)->text();
        arr.append(o);
    }

    QFile file("preguntas.json");
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "error", "No se pudo escribir en el archivo preguntas.json.");
        return;
    }

    file.write(QJsonDocument(arr).toJson()); // Guardar contenido
}

// Validar campos del formulario antes de guardar
bool GestionPreguntas::validarCampos()
{
    if (ui->textoTextEdit->toPlainText().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validacion", "El texto de la pregunta no puede quedar vacio.");
        return false;
    }

    auto ops = { ui->opA_LineEdit->text(), ui->opB_LineEdit->text(), ui->opC_LineEdit->text() };
    for (const QString &op : ops) {
        if (op.trimmed().isEmpty()) {
            QMessageBox::warning(this, "Validacion", "Todas las opciones deben completarse.");
            return false;
        }
    }

    QString c = ui->correctaLineEdit->text().trimmed().toUpper();
    if (!QRegularExpression("^[ABC]").match(c).hasMatch()) {
        QMessageBox::warning(this, "Validacion", "Respuesta correcta debe ser A, B o C.");
        return false;
    }

    return true;
}

// Agregar una nueva pregunta al modelo
void GestionPreguntas::agregarPreguntaAModelo(const QString &texto,const QString &imgBase64,const QString &a,const QString &b,const QString &c,const QString &correcta,const QString &categoria)
{
    QList<QStandardItem*> row;
    row << new QStandardItem(texto)
        << new QStandardItem(imgBase64)
        << new QStandardItem(a)
        << new QStandardItem(b)
        << new QStandardItem(c)
        << new QStandardItem(correcta)
        << new QStandardItem(categoria);
    model->appendRow(row); // Agregar fila al modelo
}

