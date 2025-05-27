/********************************************************************************
** Form generated from reading UI file 'gestion_preguntas.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_PREGUNTAS_H
#define UI_GESTION_PREGUNTAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_GestionPreguntas
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *textoLabel;
    QTextEdit *textoTextEdit;
    QLabel *imagenLabel;
    QHBoxLayout *imagenLayout;
    QLineEdit *imagenLineEdit;
    QPushButton *browseImagePushButton;
    QLabel *opA_Label;
    QLineEdit *opA_LineEdit;
    QLabel *opB_Label;
    QLineEdit *opB_LineEdit;
    QLabel *opC_Label;
    QLineEdit *opC_LineEdit;
    QLabel *correctaLabel;
    QLineEdit *correctaLineEdit;
    QLabel *categoriaLabel;
    QComboBox *categoriaComboBox;
    QHBoxLayout *buttonsLayout;
    QPushButton *crearPushButton;
    QPushButton *listarPreguntasPushButton;
    QTableView *preguntasTableView;
    QHBoxLayout *editarEliminarLayout;
    QPushButton *editarPushButton;
    QPushButton *eliminarPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GestionPreguntas)
    {
        if (GestionPreguntas->objectName().isEmpty())
            GestionPreguntas->setObjectName("GestionPreguntas");
        GestionPreguntas->resize(450, 600);
        centralwidget = new QWidget(GestionPreguntas);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        textoLabel = new QLabel(centralwidget);
        textoLabel->setObjectName("textoLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, textoLabel);

        textoTextEdit = new QTextEdit(centralwidget);
        textoTextEdit->setObjectName("textoTextEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, textoTextEdit);

        imagenLabel = new QLabel(centralwidget);
        imagenLabel->setObjectName("imagenLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, imagenLabel);

        imagenLayout = new QHBoxLayout();
        imagenLayout->setObjectName("imagenLayout");
        imagenLineEdit = new QLineEdit(centralwidget);
        imagenLineEdit->setObjectName("imagenLineEdit");

        imagenLayout->addWidget(imagenLineEdit);

        browseImagePushButton = new QPushButton(centralwidget);
        browseImagePushButton->setObjectName("browseImagePushButton");

        imagenLayout->addWidget(browseImagePushButton);


        formLayout->setLayout(1, QFormLayout::ItemRole::FieldRole, imagenLayout);

        opA_Label = new QLabel(centralwidget);
        opA_Label->setObjectName("opA_Label");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, opA_Label);

        opA_LineEdit = new QLineEdit(centralwidget);
        opA_LineEdit->setObjectName("opA_LineEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, opA_LineEdit);

        opB_Label = new QLabel(centralwidget);
        opB_Label->setObjectName("opB_Label");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, opB_Label);

        opB_LineEdit = new QLineEdit(centralwidget);
        opB_LineEdit->setObjectName("opB_LineEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, opB_LineEdit);

        opC_Label = new QLabel(centralwidget);
        opC_Label->setObjectName("opC_Label");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, opC_Label);

        opC_LineEdit = new QLineEdit(centralwidget);
        opC_LineEdit->setObjectName("opC_LineEdit");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, opC_LineEdit);

        correctaLabel = new QLabel(centralwidget);
        correctaLabel->setObjectName("correctaLabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, correctaLabel);

        correctaLineEdit = new QLineEdit(centralwidget);
        correctaLineEdit->setObjectName("correctaLineEdit");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, correctaLineEdit);

        categoriaLabel = new QLabel(centralwidget);
        categoriaLabel->setObjectName("categoriaLabel");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, categoriaLabel);

        categoriaComboBox = new QComboBox(centralwidget);
        categoriaComboBox->setObjectName("categoriaComboBox");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, categoriaComboBox);


        verticalLayout->addLayout(formLayout);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        crearPushButton = new QPushButton(centralwidget);
        crearPushButton->setObjectName("crearPushButton");

        buttonsLayout->addWidget(crearPushButton);

        listarPreguntasPushButton = new QPushButton(centralwidget);
        listarPreguntasPushButton->setObjectName("listarPreguntasPushButton");

        buttonsLayout->addWidget(listarPreguntasPushButton);


        verticalLayout->addLayout(buttonsLayout);

        preguntasTableView = new QTableView(centralwidget);
        preguntasTableView->setObjectName("preguntasTableView");

        verticalLayout->addWidget(preguntasTableView);

        editarEliminarLayout = new QHBoxLayout();
        editarEliminarLayout->setObjectName("editarEliminarLayout");
        editarPushButton = new QPushButton(centralwidget);
        editarPushButton->setObjectName("editarPushButton");

        editarEliminarLayout->addWidget(editarPushButton);

        eliminarPushButton = new QPushButton(centralwidget);
        eliminarPushButton->setObjectName("eliminarPushButton");

        editarEliminarLayout->addWidget(eliminarPushButton);


        verticalLayout->addLayout(editarEliminarLayout);

        GestionPreguntas->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GestionPreguntas);
        menubar->setObjectName("menubar");
        GestionPreguntas->setMenuBar(menubar);
        statusbar = new QStatusBar(GestionPreguntas);
        statusbar->setObjectName("statusbar");
        GestionPreguntas->setStatusBar(statusbar);

        retranslateUi(GestionPreguntas);

        QMetaObject::connectSlotsByName(GestionPreguntas);
    } // setupUi

    void retranslateUi(QMainWindow *GestionPreguntas)
    {
        GestionPreguntas->setWindowTitle(QCoreApplication::translate("GestionPreguntas", "Gesti\303\263n de Preguntas", nullptr));
        textoLabel->setText(QCoreApplication::translate("GestionPreguntas", "Texto de la Pregunta:", nullptr));
        imagenLabel->setText(QCoreApplication::translate("GestionPreguntas", "Imagen:", nullptr));
        browseImagePushButton->setText(QCoreApplication::translate("GestionPreguntas", "Browse\342\200\246", nullptr));
        opA_Label->setText(QCoreApplication::translate("GestionPreguntas", "Opci\303\263n A:", nullptr));
        opB_Label->setText(QCoreApplication::translate("GestionPreguntas", "Opci\303\263n B:", nullptr));
        opC_Label->setText(QCoreApplication::translate("GestionPreguntas", "Opci\303\263n C:", nullptr));
        correctaLabel->setText(QCoreApplication::translate("GestionPreguntas", "Respuesta Correcta (A, B o C):", nullptr));
        categoriaLabel->setText(QCoreApplication::translate("GestionPreguntas", "Categor\303\255a:", nullptr));
        crearPushButton->setText(QCoreApplication::translate("GestionPreguntas", "Crear", nullptr));
        listarPreguntasPushButton->setText(QCoreApplication::translate("GestionPreguntas", "Listar Preguntas", nullptr));
        editarPushButton->setText(QCoreApplication::translate("GestionPreguntas", "Editar Pregunta", nullptr));
        eliminarPushButton->setText(QCoreApplication::translate("GestionPreguntas", "Eliminar Pregunta", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestionPreguntas: public Ui_GestionPreguntas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_PREGUNTAS_H
