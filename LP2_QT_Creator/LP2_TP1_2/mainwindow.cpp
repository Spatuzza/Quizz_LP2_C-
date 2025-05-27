#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>

// Constructor de la ventana principal
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , usuariosWindow(nullptr)
    , preguntasWindow(nullptr)
    , categoriasWindow(nullptr)
    , juegoWindow(nullptr)
    , seleccionarJugadorDialog(nullptr)
    , globalRankingModel(new QStandardItemModel(this)) // Modelo para la tabla del ranking
{
    ui->setupUi(this); // Configura la interfaz desde el archivo .ui

    // Configuración del modelo de ranking
    globalRankingModel->setColumnCount(2);
    globalRankingModel->setHeaderData(0, Qt::Horizontal, "Usuario");
    globalRankingModel->setHeaderData(1, Qt::Horizontal, "Puntos Totales");
    ui->globalRankingTableView->setModel(globalRankingModel); // Asocia el modelo a la tabla en la interfaz

    loadGlobalRanking(); // Carga y muestra el ranking al iniciar la app
}

// Destructor: limpia la interfaz
MainWindow::~MainWindow() {
    delete ui;
}

// Evento al hacer clic en el boton de gestión de usuarios
void MainWindow::on_gestionUsuariosButton_clicked() {
    if (!usuariosWindow)
        usuariosWindow = new GestionUsuarios(this); // Se crea solo si no existe
    usuariosWindow->show();
}

// Evento al hacer clic en el botón de gestión de preguntas
void MainWindow::on_gestionPreguntasButton_clicked() {
    if (!preguntasWindow)
        preguntasWindow = new GestionPreguntas(this);
    preguntasWindow->show();
}

// Evento al hacer clic en el botón de gestión de categorías
void MainWindow::on_gestionCategoriasButton_clicked() {
    if (!categoriasWindow)
        categoriasWindow = new GestionCategorias(this);
    categoriasWindow->show();
}

// Evento al hacer clic en el botón de "Jugar"
void MainWindow::on_jugarButton_clicked() {
    delete seleccionarJugadorDialog; // Elimina cualquier diálogo anterior
    seleccionarJugadorDialog = new SeleccionarJugadorDialog(this); // Crea un nuevo diálogo

    // Si el usuario acepta el diálogo (elige jugadores)
    if (seleccionarJugadorDialog->exec() == QDialog::Accepted) {
        auto players = seleccionarJugadorDialog->selectedUsers(); // Obtiene los jugadores seleccionados

        delete juegoWindow; // Elimina cualquier ventana de juego anterior
        juegoWindow = new JuegoTurnos(this, players); // Crea una nueva partida

        // Conecta la señal de "juego terminado" para actualizar el ranking automáticamente
        connect(juegoWindow, &JuegoTurnos::gameFinished,this, &MainWindow::loadGlobalRanking);

        juegoWindow->show(); // Muestra la ventana de juego
    }
}

// Evento al hacer clic en el botón de salir
void MainWindow::on_salirButton_clicked() {
    QApplication::quit(); // Sale de la aplicación
}

// Carga y actualiza el ranking global desde el archivo resultados.json
void MainWindow::loadGlobalRanking() {
    QFile file("resultados.json");
    if (!file.open(QIODevice::ReadOnly)) return; // Si no se puede abrir, sale

    // Lee el archivo y convierte a un array JSON
    QJsonArray arr = QJsonDocument::fromJson(file.readAll()).array();
    file.close();

    QMap<QString, int> total; // Mapa para acumular puntos por usuario

    // Recorre el arreglo JSON y suma los puntos por nombre
    for (const QJsonValue &v : arr) {
        QJsonObject o = v.toObject();
        total[o.value("nombre").toString()] += o.value("puntos").toInt();
    }

    QList<QPair<QString, int>> list; // Lista ordenable con pares (nombre, puntos)
    list.reserve(total.size()); // Optimiza reserva de memoria
    for (auto it = total.constBegin(); it != total.constEnd(); ++it) {
        list.append(qMakePair(it.key(), it.value())); // Copia los pares a la lista
    }

    std::sort(list.begin(), list.end(), [](auto &a, auto &b) {
        return a.second > b.second; // Orden descendente por puntos
    });

    // Limpia el modelo anterior
    globalRankingModel->removeRows(0, globalRankingModel->rowCount());

    // Agrega las filas al modelo ordenado
    for (const auto &pair : list) {
        QList<QStandardItem*> row;
        row << new QStandardItem(pair.first) // Nombre del usuario
            << new QStandardItem(QString::number(pair.second)); // Puntos acumulados
        globalRankingModel->appendRow(row);
    }
}
