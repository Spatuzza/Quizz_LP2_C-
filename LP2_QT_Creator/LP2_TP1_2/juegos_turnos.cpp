#include "juegos_turnos.h"
#include "ui_juegos_turnos.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QBuffer>
#include <QImage>
#include <QPixmap>
#include <QStandardItem>
#include <QRandomGenerator>

// Constructor de la ventana principal del juego por turnos
JuegoTurnos::JuegoTurnos(QWidget *parent, const QStringList &players)
    : QMainWindow(parent)
    , ui(new Ui::JuegoTurnos)
    , rankingModel(new QStandardItemModel(this)) // Modelo para mostrar el ranking en tabla
    , playerCount(players.size())                // Cantidad de jugadores
    , playerNames(players)                       // Lista de nombres de jugadores
    , scores(playerCount, 0)                     // Vector de puntajes inicializados en 0
    , currentPlayer(0)                           // Comienza el jugador 0
    , questionIndex(-1)                          // No hay pregunta seleccionada aun
{
    ui->setupUi(this); // Configura la interfaz grafica
    ui->questionImageLabel->setAlignment(Qt::AlignCenter); // Centra la imagen de la pregunta

    // Configura columnas y encabezados del ranking
    rankingModel->setColumnCount(2);
    rankingModel->setHeaderData(0, Qt::Horizontal, "Jugador");
    rankingModel->setHeaderData(1, Qt::Horizontal, "Puntos");
    ui->rankingTableView->setModel(rankingModel);

    loadPreguntas(); // Carga las preguntas desde el archivo
    questionIndex = QRandomGenerator::global()->bounded(preguntas.size()); // Selecciona una pregunta aleatoria
    showPregunta(questionIndex); // Muestra la pregunta en pantalla
    ui->playerTurnLabel->setText(playerNames.at(currentPlayer)); // Muestra el nombre del jugador actual
}

// Destructor de la clase
JuegoTurnos::~JuegoTurnos() {
    delete ui;
}

// Carga preguntas desde el archivo preguntas.json
void JuegoTurnos::loadPreguntas() {
    preguntas.clear(); // Limpia la lista antes de cargar

    QFile file("preguntas.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonArray arr = QJsonDocument::fromJson(file.readAll()).array();
    file.close();

    // Convierte cada objeto JSON en una instancia de Pregunta
    for (auto v : arr) {
        QJsonObject o = v.toObject();
        Pregunta p;
        p.texto     = o.value("texto").toString();
        p.imgBase64 = o.value("imagen").toString();
        p.opA       = o.value("opA").toString();
        p.opB       = o.value("opB").toString();
        p.opC       = o.value("opC").toString();
        p.correcta  = o.value("correcta").toString();
        p.categoria = o.value("categoria").toString();
        preguntas.append(p);
    }
}

// Muestra una pregunta especifica segun su indice
void JuegoTurnos::showPregunta(int index) {
    const auto &p = preguntas.at(index); // Obtiene la pregunta

    ui->questionTextLabel->setText(p.texto); // Muestra el texto

    // Decodifica y muestra la imagen si existe
    if (!p.imgBase64.isEmpty()) {
        QByteArray data = QByteArray::fromBase64(p.imgBase64.toLatin1());
        QImage img;
        img.loadFromData(data);
        ui->questionImageLabel->setPixmap(
            QPixmap::fromImage(img).scaled(300, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        ui->questionImageLabel->clear(); // Borra la imagen anterior si no hay nueva
    }

    // Asigna los textos a los botones de opcion
    ui->optionAButton->setText("A. " + p.opA);
    ui->optionBButton->setText("B. " + p.opB);
    ui->optionCButton->setText("C. " + p.opC);
    ui->feedbackLabel->clear(); // Limpia retroalimentacion anterior
}

// Maneja la seleccion de la opcion A
void JuegoTurnos::on_optionAButton_clicked() {
    bool correct = (preguntas[questionIndex].correcta == "A");
    if (correct) scores[currentPlayer]++; // Suma punto si acierta
    ui->feedbackLabel->setText(correct ? "¡Correcto!" : "Incorrecto.");

    updateRanking(); // Actualiza tabla de puntajes

    currentPlayer = (currentPlayer + 1) % playerCount; // Cambia al siguiente jugador
    questionIndex = QRandomGenerator::global()->bounded(preguntas.size()); // Nueva pregunta aleatoria
    showPregunta(questionIndex); // Mostrarla
    ui->playerTurnLabel->setText(playerNames.at(currentPlayer)); // Actualizar etiqueta de turno
}

// Maneja la seleccion de la opcion B
void JuegoTurnos::on_optionBButton_clicked() {
    bool correct = (preguntas[questionIndex].correcta == "B");
    if (correct) scores[currentPlayer]++;
    ui->feedbackLabel->setText(correct ? "¡Correcto!" : "Incorrecto.");
    updateRanking();
    currentPlayer = (currentPlayer + 1) % playerCount;
    questionIndex = QRandomGenerator::global()->bounded(preguntas.size());
    showPregunta(questionIndex);
    ui->playerTurnLabel->setText(playerNames.at(currentPlayer));
}

// Maneja la seleccion de la opcion C
void JuegoTurnos::on_optionCButton_clicked() {
    bool correct = (preguntas[questionIndex].correcta == "C");
    if (correct) scores[currentPlayer]++;
    ui->feedbackLabel->setText(correct ? "¡Correcto!" : "Incorrecto.");
    updateRanking();
    currentPlayer = (currentPlayer + 1) % playerCount;
    questionIndex = QRandomGenerator::global()->bounded(preguntas.size());
    showPregunta(questionIndex);
    ui->playerTurnLabel->setText(playerNames.at(currentPlayer));
}

// Finaliza el juego, guarda resultados y cierra la ventana
void JuegoTurnos::on_finishButton_clicked() {
    QJsonArray outArr;
    QFile outFile("resultados.json");

    // Si ya hay un archivo, cargar su contenido previo
    if (outFile.open(QIODevice::ReadOnly)) {
        QJsonDocument prevDoc = QJsonDocument::fromJson(outFile.readAll());
        if (prevDoc.isArray()) outArr = prevDoc.array();
        outFile.close();
    }

    // Agregar los puntajes actuales al arreglo
    for (int i = 0; i < playerCount; ++i) {
        QJsonObject o;
        o["nombre"] = playerNames.at(i);
        o["puntos"] = scores.at(i);
        outArr.append(o);
    }

    // Guardar en el archivo de resultados
    if (outFile.open(QIODevice::WriteOnly)) {
        outFile.write(QJsonDocument(outArr).toJson());
        outFile.close();
    }

    emit gameFinished(); // Emite una señal para que otras ventanas se actualicen (como ranking global)
    close();             // Cierra la ventana de juego
}

// Actualiza la tabla de ranking con los puntajes actuales
void JuegoTurnos::updateRanking() {
    rankingModel->removeRows(0, rankingModel->rowCount()); // Borra filas anteriores

    // Agrega una fila por jugador con su nombre y puntaje actual
    for (int i = 0; i < playerCount; ++i) {
        QList<QStandardItem*> row;
        row << new QStandardItem(playerNames.at(i))
            << new QStandardItem(QString::number(scores.at(i)));
        rankingModel->appendRow(row);
    }
}
