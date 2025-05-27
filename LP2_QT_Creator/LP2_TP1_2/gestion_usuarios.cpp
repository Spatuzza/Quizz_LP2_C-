// Archivo: gestion_usuarios.cpp
#include "gestion_usuarios.h"
#include "ui_gestion_usuarios.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QStandardItem>
#include <QRegularExpression>

// Constructor de la ventana de gestion de usuarios
GestionUsuarios::GestionUsuarios(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionUsuarios),
    model(new QStandardItemModel(this)), // Modelo para mostrar los usuarios en la tabla
    editingRow(-1) // Si es -1, no se esta editando ninguna fila
{
    ui->setupUi(this); // Inicializa la interfaz grafica

    // Configurar la tabla con una sola columna ("Nombre")
    model->setColumnCount(1);
    model->setHeaderData(0, Qt::Horizontal, "Nombre");
    ui->usuariosTableView->setModel(model); // Asociar el modelo a la tabla

    cargarUsuariosDeJson(); // Cargar usuarios existentes desde el archivo usuarios.json
}

// Destructor: libera la memoria de la interfaz
GestionUsuarios::~GestionUsuarios()
{
    delete ui;
}

// Evento al presionar el boton "Crear" o "Guardar"
void GestionUsuarios::on_crearPushButton_clicked()
{
    // Verifica si los datos ingresados son validos
    if (!validarCampos())
        return;

    QString nombre = ui->nombreLineEdit->text().trimmed(); // Obtener el nombre ingresado

    if (editingRow >= 0) {
        // Si se esta editando una fila existente, actualizar su valor
        if (auto item = model->item(editingRow, 0))
            item->setText(nombre);

        ui->crearPushButton->setText("Crear"); // Volver el texto del boton a "Crear"
        editingRow = -1; // Finalizar modo edicion
    } else {
        // Si no se esta editando, agregar un nuevo usuario
        agregarUsuarioALista(nombre);
    }

    guardarUsuariosEnJson(); // Guardar todos los usuarios en el archivo
    ui->nombreLineEdit->clear(); // Limpiar el campo de texto
}

// Evento al presionar "Listar usuarios"
void GestionUsuarios::on_listarUsuariosPushButton_clicked()
{
    cargarUsuariosDeJson(); // Recarga los datos desde el archivo
}

// Evento al presionar "Editar"
void GestionUsuarios::on_editarPushButton_clicked()
{
    // Obtener la fila actualmente seleccionada en la tabla
    auto idx = ui->usuariosTableView->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Error", "Por favor, seleccione un usuario para editar.");
        return;
    }

    editingRow = idx.row(); // Guardar la fila seleccionada para edicion

    // Cargar el nombre del usuario seleccionado en el campo de texto
    QString nombre = model->item(editingRow, 0)->text();
    ui->nombreLineEdit->setText(nombre);
    ui->crearPushButton->setText("Guardar"); // Cambiar el boton a modo edicion
}

// Evento al presionar "Eliminar"
void GestionUsuarios::on_eliminarPushButton_clicked()
{
    auto idx = ui->usuariosTableView->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Error", "Seleccione un usuario para eliminar.");
        return;
    }

    model->removeRow(idx.row()); // Eliminar la fila del modelo
    guardarUsuariosEnJson();     // Guardar el estado actualizado en el archivo
}

// Carga los usuarios desde el archivo usuarios.json y los agrega al modelo
void GestionUsuarios::cargarUsuariosDeJson()
{
    model->removeRows(0, model->rowCount()); // Limpiar modelo antes de cargar

    QFile file("usuarios.json");
    if (!file.open(QIODevice::ReadOnly))
        return;

    auto doc = QJsonDocument::fromJson(file.readAll()); // Convertir contenido a JSON
    file.close();

    // Recorrer cada entrada del arreglo JSON
    for (auto val : doc.array()) {
        QString nombre = val.toObject().value("nombre").toString();
        agregarUsuarioALista(nombre); // Agregar al modelo
    }
}

// Guarda el contenido actual del modelo en el archivo usuarios.json
void GestionUsuarios::guardarUsuariosEnJson()
{
    QJsonArray arr;

    // Recorrer todas las filas del modelo
    for (int r = 0; r < model->rowCount(); ++r) {
        QJsonObject o;
        o["nombre"] = model->item(r, 0)->text(); // Obtener el texto de la columna 0
        arr.append(o);
    }

    QJsonDocument doc(arr);
    QFile file("usuarios.json");

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Error", "No se pudo guardar usuarios.json");
        return;
    }

    file.write(doc.toJson()); // Escribir el archivo con el contenido JSON
    file.close();
}

// Valida que el campo de nombre este completo y tenga un formato valido
bool GestionUsuarios::validarCampos()
{
    QString nombre = ui->nombreLineEdit->text().trimmed();

    if (nombre.isEmpty()) {
        QMessageBox::warning(this, "Validacion", "El nombre no puede estar vacio.");
        return false;
    }

    // Expresion regular para permitir solo letras y espacios
    // Incluye letras con tildes y la letra Ò en mayusculas y minusculas
    static const QRegularExpression re(QStringLiteral("^[A-Za-z¡…Õ”⁄·ÈÌÛ˙—Ò ]+$"));

    auto match = re.match(nombre);
    if (!match.hasMatch()) {
        QMessageBox::warning(this, "Validacion", "Solo letras y espacios estan permitidos.");
        return false;
    }

    return true;
}

// Agrega un nuevo usuario (nombre) al modelo de la tabla
void GestionUsuarios::agregarUsuarioALista(const QString &nombre)
{
    QList<QStandardItem*> row;
    row << new QStandardItem(nombre); // Crear celda con el nombre del usuario
    model->appendRow(row);            // Agregar fila al modelo
}
