#include "gestion_categorias.h"
#include "ui_gestion_categorias.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>

// Constructor de la ventana de gestión de categorías
GestionCategorias::GestionCategorias(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestionCategorias),
    model(new QStandardItemModel(this)), // Modelo que usaremos para mostrar y editar las categorías
    editingRow(-1) // Variable para saber si estamos editando una fila existente
{
    ui->setupUi(this); // Carga la interfaz desde el archivo .ui

    // Configuración del modelo de datos
    model->setColumnCount(2);
    model->setHeaderData(0, Qt::Horizontal, "Nombre");
    model->setHeaderData(1, Qt::Horizontal, "Descripción");
    ui->categoriasTableView->setModel(model); // Asocia el modelo a la tabla en la UI

    cargarCategoriasDeJson(); // Carga las categorías existentes al iniciar
}

// Destructor: libera la interfaz
GestionCategorias::~GestionCategorias()
{
    delete ui;
}

// Evento al hacer clic en el botón "Crear" o "Guardar"
void GestionCategorias::on_crearCategoriaPushButton_clicked()
{
    if (!validarCampos()) return; // Verifica que el campo nombre no esté vacío

    QString nombre = ui->nombreLineEdit->text().trimmed(); // Obtiene el nombre ingresado
    QString desc   = ui->descripcionTextEdit->toPlainText().trimmed(); // Obtiene la descripción ingresada

    // Si se está editando una categoría ya existente
    if (editingRow >= 0) {
        model->item(editingRow, 0)->setText(nombre); // Actualiza el nombre
        model->item(editingRow, 1)->setText(desc);   // Actualiza la descripción
        ui->crearCategoriaPushButton->setText("Crear"); // Vuelve el botón a su estado original
        editingRow = -1; // Finaliza modo edición
    } else {
        agregarCategoriaAlModelo(nombre, desc); // Agrega una nueva fila al modelo
    }

    guardarCategoriasEnJson(); // Guarda los datos actualizados al archivo
    ui->nombreLineEdit->clear(); // Limpia el formulario
    ui->descripcionTextEdit->clear();
}

// Evento al hacer clic en "Listar categorías"
void GestionCategorias::on_listarCategoriasPushButton_clicked()
{
    cargarCategoriasDeJson(); // Recarga el archivo y actualiza la tabla
}

// Evento al hacer clic en "Editar categoría"
void GestionCategorias::on_editarCategoriaPushButton_clicked()
{
    auto idx = ui->categoriasTableView->currentIndex(); // Obtiene la fila seleccionada
    if (!idx.isValid()) {
        QMessageBox::warning(this, "error", "Seleccione una categoría para editar.");
        return;
    }

    // Guarda el índice de la fila que se va a editar
    editingRow = idx.row();

    // Carga los datos de la fila seleccionada en los campos del formulario
    ui->nombreLineEdit->setText(model->item(editingRow, 0)->text());
    ui->descripcionTextEdit->setText(model->item(editingRow, 1)->text());
    ui->crearCategoriaPushButton->setText("Guardar"); // Cambia el texto del botón
}

// Evento al hacer clic en "Eliminar categoría"
void GestionCategorias::on_eliminarCategoriaPushButton_clicked()
{
    auto idx = ui->categoriasTableView->currentIndex(); // Obtiene la fila seleccionada
    if (!idx.isValid()) {
        QMessageBox::warning(this, "error", "Seleccione una categoría para eliminar.");
        return;
    }

    model->removeRow(idx.row()); // Elimina la fila del modelo
    guardarCategoriasEnJson();  // Guarda el modelo actualizado
}

// Carga las categorías desde el archivo JSON y las muestra en la tabla
void GestionCategorias::cargarCategoriasDeJson()
{
    model->removeRows(0, model->rowCount()); // Limpia la tabla actual

    QFile file("categorias.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    auto doc = QJsonDocument::fromJson(file.readAll()); // Lee y convierte el archivo a documento JSON
    file.close();

    // Recorre cada objeto del arreglo JSON y lo agrega al modelo
    for (auto val : doc.array()) {
        auto o = val.toObject();
        agregarCategoriaAlModelo(
            o.value("nombre").toString(),
            o.value("descripcion").toString()
        );
    }
}

// Guarda las categorías del modelo en el archivo JSON
void GestionCategorias::guardarCategoriasEnJson()
{
    QJsonArray arr;

    // Recorre todas las filas del modelo y convierte cada una en un objeto JSON
    for (int r = 0; r < model->rowCount(); ++r) {
        QJsonObject o;
        o["nombre"]      = model->item(r, 0)->text();
        o["descripcion"] = model->item(r, 1)->text();
        arr.append(o);
    }

    QJsonDocument doc(arr); // Crea el documento JSON a partir del arreglo

    QFile file("categorias.json");
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "error", "No se pudo escribir categorias.json");
        return;
    }

    file.write(doc.toJson()); // Escribe el documento en el archivo
}

// Verifica que los campos obligatorios estén completos
bool GestionCategorias::validarCampos()
{
    if (ui->nombreLineEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validación", "El nombre no puede quedar vacío.");
        return false;
    }
    return true;
}

// Agrega una fila nueva al modelo con el nombre y descripción dados
void GestionCategorias::agregarCategoriaAlModelo(const QString &nombre, const QString &descripcion)
{
    QList<QStandardItem*> row;
    row << new QStandardItem(nombre)
        << new QStandardItem(descripcion);
    model->appendRow(row); // Añade la fila al modelo
}
