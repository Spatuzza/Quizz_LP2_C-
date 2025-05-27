/********************************************************************************
** Form generated from reading UI file 'gestion_usuarios.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_USUARIOS_H
#define UI_GESTION_USUARIOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionUsuarios
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nombreLabel;
    QLineEdit *nombreLineEdit;
    QHBoxLayout *buttonsLayout;
    QPushButton *crearPushButton;
    QTableView *usuariosTableView;
    QHBoxLayout *editarEliminarLayout;
    QPushButton *editarPushButton;
    QPushButton *eliminarPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GestionUsuarios)
    {
        if (GestionUsuarios->objectName().isEmpty())
            GestionUsuarios->setObjectName("GestionUsuarios");
        GestionUsuarios->resize(400, 450);
        centralwidget = new QWidget(GestionUsuarios);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        nombreLabel = new QLabel(centralwidget);
        nombreLabel->setObjectName("nombreLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, nombreLabel);

        nombreLineEdit = new QLineEdit(centralwidget);
        nombreLineEdit->setObjectName("nombreLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nombreLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        crearPushButton = new QPushButton(centralwidget);
        crearPushButton->setObjectName("crearPushButton");

        buttonsLayout->addWidget(crearPushButton);


        verticalLayout->addLayout(buttonsLayout);

        usuariosTableView = new QTableView(centralwidget);
        usuariosTableView->setObjectName("usuariosTableView");

        verticalLayout->addWidget(usuariosTableView);

        editarEliminarLayout = new QHBoxLayout();
        editarEliminarLayout->setObjectName("editarEliminarLayout");
        editarPushButton = new QPushButton(centralwidget);
        editarPushButton->setObjectName("editarPushButton");

        editarEliminarLayout->addWidget(editarPushButton);

        eliminarPushButton = new QPushButton(centralwidget);
        eliminarPushButton->setObjectName("eliminarPushButton");

        editarEliminarLayout->addWidget(eliminarPushButton);


        verticalLayout->addLayout(editarEliminarLayout);

        GestionUsuarios->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GestionUsuarios);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 21));
        GestionUsuarios->setMenuBar(menubar);
        statusbar = new QStatusBar(GestionUsuarios);
        statusbar->setObjectName("statusbar");
        GestionUsuarios->setStatusBar(statusbar);

        retranslateUi(GestionUsuarios);

        QMetaObject::connectSlotsByName(GestionUsuarios);
    } // setupUi

    void retranslateUi(QMainWindow *GestionUsuarios)
    {
        GestionUsuarios->setWindowTitle(QCoreApplication::translate("GestionUsuarios", "Gesti\303\263n de Usuarios", nullptr));
        nombreLabel->setText(QCoreApplication::translate("GestionUsuarios", "Nombre:", nullptr));
        crearPushButton->setText(QCoreApplication::translate("GestionUsuarios", "Crear", nullptr));
        editarPushButton->setText(QCoreApplication::translate("GestionUsuarios", "Editar Usuario", nullptr));
        eliminarPushButton->setText(QCoreApplication::translate("GestionUsuarios", "Eliminar Usuario", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionUsuarios: public Ui_GestionUsuarios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_USUARIOS_H
