#ifndef GESTION_CATEGORIAS_H
#define GESTION_CATEGORIAS_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class GestionCategorias;
}

class GestionCategorias : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionCategorias(QWidget *parent = nullptr);
    ~GestionCategorias();

private slots:
    void on_crearCategoriaPushButton_clicked();
    void on_listarCategoriasPushButton_clicked();
    void on_editarCategoriaPushButton_clicked();
    void on_eliminarCategoriaPushButton_clicked();

private:
    Ui::GestionCategorias *ui;// puntero a ui
    QStandardItemModel    *model;
    int                    editingRow;

    void cargarCategoriasDeJson();
    void guardarCategoriasEnJson();
    bool validarCampos();
    void agregarCategoriaAlModelo(const QString &nombre,
                                  const QString &descripcion);
};

#endif
