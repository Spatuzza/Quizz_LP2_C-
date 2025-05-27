// gestion_usuarios.h
#ifndef GESTION_USUARIOS_H
#define GESTION_USUARIOS_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class GestionUsuarios;
}

class GestionUsuarios : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionUsuarios(QWidget *parent = nullptr);
    ~GestionUsuarios();

private slots:
    void on_crearPushButton_clicked();
    void on_listarUsuariosPushButton_clicked();
    void on_editarPushButton_clicked();
    void on_eliminarPushButton_clicked();

private:
    Ui::GestionUsuarios *ui;
    QStandardItemModel *model;
    int editingRow;
    void cargarUsuariosDeJson();
    void guardarUsuariosEnJson();
    bool validarCampos();
    void agregarUsuarioALista(const QString &nombre);
};

#endif

