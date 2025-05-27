/********************************************************************************
** Form generated from reading UI file 'gestion_categorias.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_CATEGORIAS_H
#define UI_GESTION_CATEGORIAS_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionCategorias
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nombreLabel;
    QLineEdit *nombreLineEdit;
    QLabel *descripcionLabel;
    QTextEdit *descripcionTextEdit;
    QHBoxLayout *buttonsLayout;
    QPushButton *crearCategoriaPushButton;
    QPushButton *listarCategoriasPushButton;
    QTableView *categoriasTableView;
    QHBoxLayout *editarEliminarLayout;
    QPushButton *editarCategoriaPushButton;
    QPushButton *eliminarCategoriaPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GestionCategorias)
    {
        if (GestionCategorias->objectName().isEmpty())
            GestionCategorias->setObjectName("GestionCategorias");
        GestionCategorias->resize(400, 450);
        centralwidget = new QWidget(GestionCategorias);
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

        descripcionLabel = new QLabel(centralwidget);
        descripcionLabel->setObjectName("descripcionLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, descripcionLabel);

        descripcionTextEdit = new QTextEdit(centralwidget);
        descripcionTextEdit->setObjectName("descripcionTextEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, descripcionTextEdit);


        verticalLayout->addLayout(formLayout);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        crearCategoriaPushButton = new QPushButton(centralwidget);
        crearCategoriaPushButton->setObjectName("crearCategoriaPushButton");

        buttonsLayout->addWidget(crearCategoriaPushButton);

        listarCategoriasPushButton = new QPushButton(centralwidget);
        listarCategoriasPushButton->setObjectName("listarCategoriasPushButton");

        buttonsLayout->addWidget(listarCategoriasPushButton);


        verticalLayout->addLayout(buttonsLayout);

        categoriasTableView = new QTableView(centralwidget);
        categoriasTableView->setObjectName("categoriasTableView");

        verticalLayout->addWidget(categoriasTableView);

        editarEliminarLayout = new QHBoxLayout();
        editarEliminarLayout->setObjectName("editarEliminarLayout");
        editarCategoriaPushButton = new QPushButton(centralwidget);
        editarCategoriaPushButton->setObjectName("editarCategoriaPushButton");

        editarEliminarLayout->addWidget(editarCategoriaPushButton);

        eliminarCategoriaPushButton = new QPushButton(centralwidget);
        eliminarCategoriaPushButton->setObjectName("eliminarCategoriaPushButton");

        editarEliminarLayout->addWidget(eliminarCategoriaPushButton);


        verticalLayout->addLayout(editarEliminarLayout);

        GestionCategorias->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GestionCategorias);
        menubar->setObjectName("menubar");
        GestionCategorias->setMenuBar(menubar);
        statusbar = new QStatusBar(GestionCategorias);
        statusbar->setObjectName("statusbar");
        GestionCategorias->setStatusBar(statusbar);

        retranslateUi(GestionCategorias);

        QMetaObject::connectSlotsByName(GestionCategorias);
    } // setupUi

    void retranslateUi(QMainWindow *GestionCategorias)
    {
        GestionCategorias->setWindowTitle(QCoreApplication::translate("GestionCategorias", "Gesti\303\263n de Categor\303\255as", nullptr));
        nombreLabel->setText(QCoreApplication::translate("GestionCategorias", "Nombre:", nullptr));
        descripcionLabel->setText(QCoreApplication::translate("GestionCategorias", "Descripci\303\263n:", nullptr));
        crearCategoriaPushButton->setText(QCoreApplication::translate("GestionCategorias", "Crear", nullptr));
        listarCategoriasPushButton->setText(QCoreApplication::translate("GestionCategorias", "Listar Categor\303\255as", nullptr));
        editarCategoriaPushButton->setText(QCoreApplication::translate("GestionCategorias", "Editar Categor\303\255a", nullptr));
        eliminarCategoriaPushButton->setText(QCoreApplication::translate("GestionCategorias", "Eliminar Categor\303\255a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionCategorias: public Ui_GestionCategorias {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_CATEGORIAS_H
