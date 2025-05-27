#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "gestion_usuarios.h"
#include "gestion_preguntas.h"
#include "gestion_categorias.h"
#include "juegos_turnos.h"
#include "seleccionar_jugador.h"

// Macro que abre un espacio de nombres interno de Qt
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }  // Declaracion anticipada de la clase de UI generada por Qt Designer
QT_END_NAMESPACE

// Definicion de la clase MainWindow, que hereda de QMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT  // Macro necesaria para que funcionen las señales y slots de Qt

public:
    explicit MainWindow(QWidget *parent = nullptr); // Constructor
    ~MainWindow();                                  // Destructor

private slots:
    // Slots conectados a los botones de la interfaz
    void on_gestionUsuariosButton_clicked();     // Abre la ventana de gestion de usuarios
    void on_gestionPreguntasButton_clicked();    // Abre la ventana de gestion de preguntas
    void on_gestionCategoriasButton_clicked();   // Abre la ventana de gestion de categorias
    void on_jugarButton_clicked();               // Abre el dialogo para seleccionar jugadores y luego iniciar el juego
    void on_salirButton_clicked();               // Cierra la aplicacion
    void loadGlobalRanking();                    // Carga y actualiza el ranking global de jugadores

private:
    Ui::MainWindow *ui;                          // Puntero a la interfaz grafica generada por Qt Designer
    // Ventanas auxiliares utilizadas por la ventana principal
    GestionUsuarios *usuariosWindow;            // Gestion de usuarios
    GestionPreguntas *preguntasWindow;          // Gestion de preguntas
    GestionCategorias *categoriasWindow;        // Gestion de categorias
    JuegoTurnos *juegoWindow;                   // Ventana del juego por turnos
    SeleccionarJugadorDialog *seleccionarJugadorDialog; // Dialogo para elegir jugadores

    QStandardItemModel *globalRankingModel;     // Modelo de datos para el ranking global
};

#endif // MAINWINDOW_H
