/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QPushButton *gestionUsuariosButton;
    QPushButton *gestionPreguntasButton;
    QPushButton *gestionCategoriasButton;
    QPushButton *jugarButton;
    QPushButton *salirButton;
    QGroupBox *globalRankingGroup;
    QVBoxLayout *globalRankingLayout;
    QTableView *globalRankingTableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gestionUsuariosButton = new QPushButton(centralwidget);
        gestionUsuariosButton->setObjectName("gestionUsuariosButton");

        verticalLayout->addWidget(gestionUsuariosButton);

        gestionPreguntasButton = new QPushButton(centralwidget);
        gestionPreguntasButton->setObjectName("gestionPreguntasButton");

        verticalLayout->addWidget(gestionPreguntasButton);

        gestionCategoriasButton = new QPushButton(centralwidget);
        gestionCategoriasButton->setObjectName("gestionCategoriasButton");

        verticalLayout->addWidget(gestionCategoriasButton);

        jugarButton = new QPushButton(centralwidget);
        jugarButton->setObjectName("jugarButton");

        verticalLayout->addWidget(jugarButton);

        salirButton = new QPushButton(centralwidget);
        salirButton->setObjectName("salirButton");

        verticalLayout->addWidget(salirButton);

        globalRankingGroup = new QGroupBox(centralwidget);
        globalRankingGroup->setObjectName("globalRankingGroup");
        globalRankingLayout = new QVBoxLayout(globalRankingGroup);
        globalRankingLayout->setObjectName("globalRankingLayout");
        globalRankingTableView = new QTableView(globalRankingGroup);
        globalRankingTableView->setObjectName("globalRankingTableView");

        globalRankingLayout->addWidget(globalRankingTableView);


        verticalLayout->addWidget(globalRankingGroup);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Men\303\272 Principal", nullptr));
        gestionUsuariosButton->setText(QCoreApplication::translate("MainWindow", "Gesti\303\263n Usuarios", nullptr));
        gestionPreguntasButton->setText(QCoreApplication::translate("MainWindow", "Gesti\303\263n Preguntas", nullptr));
        gestionCategoriasButton->setText(QCoreApplication::translate("MainWindow", "Gesti\303\263n Categor\303\255as", nullptr));
        jugarButton->setText(QCoreApplication::translate("MainWindow", "Jugar", nullptr));
        salirButton->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        globalRankingGroup->setTitle(QCoreApplication::translate("MainWindow", "Ranking Global", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
