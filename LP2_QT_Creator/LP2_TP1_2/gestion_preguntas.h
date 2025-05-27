#ifndef GESTION_PREGUNTAS_H
#define GESTION_PREGUNTAS_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class GestionPreguntas;
}

class GestionPreguntas : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionPreguntas(QWidget *parent = nullptr);
    ~GestionPreguntas();

private slots:
    void on_crearPushButton_clicked();
    void on_listarPreguntasPushButton_clicked();
    void on_browseImagePushButton_clicked();
    void on_editarPushButton_clicked();
    void on_eliminarPushButton_clicked();

private:
    Ui::GestionPreguntas *ui;
    QStandardItemModel   *model;
    int                   editingRow;

    void cargarPreguntasDeJson();
    void guardarPreguntasEnJson();
    bool validarCampos();
    void agregarPreguntaAModelo(const QString &texto,const QString &imgBase64,const QString &a,const QString &b,const QString &c,const QString &correcta,const QString &categoria);
};

#endif
