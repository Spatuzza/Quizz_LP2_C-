#include "seleccionar_jugador.h"
#include "ui_seleccionar_jugador.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

// Constructor del diálogo para seleccionar jugadores
SeleccionarJugadorDialog::SeleccionarJugadorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SeleccionarJugadorDialog)
{
    ui->setupUi(this); // Inicializa la interfaz desde el archivo .ui

    // Abrimos el archivo JSON que contiene los usuarios
    QFile file("usuarios.json");
    if (file.open(QIODevice::ReadOnly)) {
        // Convertimos el contenido del archivo en un arreglo JSON
        QJsonArray arr = QJsonDocument::fromJson(file.readAll()).array();
        
        // Extraemos los nombres de usuario y los guardamos en la lista 'users'
        for (auto v : arr) {
            users.append(v.toObject().value("nombre").toString());
        }

        file.close(); // Cerramos el archivo
    }

    // Agregamos los nombres al widget de lista en la interfaz
    ui->listWidgetUsers->addItems(users);

    // Establecemos como valor predeterminado 1 jugador
    ui->spinBoxCount->setValue(1);
}

// Destructor: libera la memoria de la interfaz
SeleccionarJugadorDialog::~SeleccionarJugadorDialog() {
    delete ui;
}

// Devuelve la lista de usuarios seleccionados en el widget de lista
QStringList SeleccionarJugadorDialog::selectedUsers() const {
    QStringList sel;

    // Recorremos todos los ítems seleccionados en la lista y los agregamos al resultado
    for (auto *item : ui->listWidgetUsers->selectedItems()) {
        sel << item->text();
    }

    return sel; // Devolvemos la lista final
}

// Se llama automaticamente cuando cambia el valor del spinbox (cantidad de jugadores)
void SeleccionarJugadorDialog::on_spinBoxCount_valueChanged(int count) {
    // Si hay mas de un jugador, permitimos seleccionar múltiples usuarios
    // Si no, solo se puede seleccionar uno
    ui->listWidgetUsers->setSelectionMode(
        count > 1 ? QAbstractItemView::MultiSelection : QAbstractItemView::SingleSelection);
}

// Se ejecuta cuando se presiona el botón "Aceptar"
void SeleccionarJugadorDialog::on_buttonOk_clicked() {
    // Solo se acepta el diálogo si se selecciono exactamente la cantidad indicada de jugadores
    if (ui->listWidgetUsers->selectedItems().size() == ui->spinBoxCount->value()) {
        accept(); // Cierra el diálogo con resultado "aceptado"
    }
}

// Se ejecuta cuando se presiona el botón "Cancelar"
void SeleccionarJugadorDialog::on_buttonCancel_clicked() {
    reject(); // Cierra el diálogo con resultado "rechazado"
}

