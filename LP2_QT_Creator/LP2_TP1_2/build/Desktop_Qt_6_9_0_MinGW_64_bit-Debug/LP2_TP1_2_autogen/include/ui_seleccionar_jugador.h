/********************************************************************************
** Form generated from reading UI file 'seleccionar_jugador.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECCIONAR_JUGADOR_H
#define UI_SELECCIONAR_JUGADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SeleccionarJugadorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *countLayout;
    QLabel *labelCount;
    QSpinBox *spinBoxCount;
    QListWidget *listWidgetUsers;
    QHBoxLayout *buttonsLayout;
    QPushButton *buttonOk;
    QPushButton *buttonCancel;

    void setupUi(QDialog *SeleccionarJugadorDialog)
    {
        if (SeleccionarJugadorDialog->objectName().isEmpty())
            SeleccionarJugadorDialog->setObjectName("SeleccionarJugadorDialog");
        verticalLayout = new QVBoxLayout(SeleccionarJugadorDialog);
        verticalLayout->setObjectName("verticalLayout");
        countLayout = new QHBoxLayout();
        countLayout->setObjectName("countLayout");
        labelCount = new QLabel(SeleccionarJugadorDialog);
        labelCount->setObjectName("labelCount");

        countLayout->addWidget(labelCount);

        spinBoxCount = new QSpinBox(SeleccionarJugadorDialog);
        spinBoxCount->setObjectName("spinBoxCount");
        spinBoxCount->setMinimum(1);
        spinBoxCount->setMaximum(8);

        countLayout->addWidget(spinBoxCount);


        verticalLayout->addLayout(countLayout);

        listWidgetUsers = new QListWidget(SeleccionarJugadorDialog);
        listWidgetUsers->setObjectName("listWidgetUsers");

        verticalLayout->addWidget(listWidgetUsers);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        buttonOk = new QPushButton(SeleccionarJugadorDialog);
        buttonOk->setObjectName("buttonOk");

        buttonsLayout->addWidget(buttonOk);

        buttonCancel = new QPushButton(SeleccionarJugadorDialog);
        buttonCancel->setObjectName("buttonCancel");

        buttonsLayout->addWidget(buttonCancel);


        verticalLayout->addLayout(buttonsLayout);


        retranslateUi(SeleccionarJugadorDialog);

        QMetaObject::connectSlotsByName(SeleccionarJugadorDialog);
    } // setupUi

    void retranslateUi(QDialog *SeleccionarJugadorDialog)
    {
        SeleccionarJugadorDialog->setWindowTitle(QCoreApplication::translate("SeleccionarJugadorDialog", "Seleccionar Jugadores", nullptr));
        labelCount->setText(QCoreApplication::translate("SeleccionarJugadorDialog", "Jugadores:", nullptr));
        buttonOk->setText(QCoreApplication::translate("SeleccionarJugadorDialog", "Aceptar", nullptr));
        buttonCancel->setText(QCoreApplication::translate("SeleccionarJugadorDialog", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeleccionarJugadorDialog: public Ui_SeleccionarJugadorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECCIONAR_JUGADOR_H
