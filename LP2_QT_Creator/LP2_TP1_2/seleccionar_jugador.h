#ifndef SELECCIONAR_JUGADOR_H
#define SELECCIONAR_JUGADOR_H

#include <QDialog>
#include <QStringList>

namespace Ui { class SeleccionarJugadorDialog; }

class SeleccionarJugadorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SeleccionarJugadorDialog(QWidget *parent = nullptr);
    ~SeleccionarJugadorDialog();
    QStringList selectedUsers() const;

private slots:
    void on_spinBoxCount_valueChanged(int count);
    void on_buttonOk_clicked();
    void on_buttonCancel_clicked();

private:
    Ui::SeleccionarJugadorDialog *ui;
    QStringList users;
};

#endif
