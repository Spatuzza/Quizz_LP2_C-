/********************************************************************************
** Form generated from reading UI file 'juegos_turnos.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUEGOS_TURNOS_H
#define UI_JUEGOS_TURNOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JuegoTurnos
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QGroupBox *questionGroup;
    QVBoxLayout *questionLayout;
    QLabel *playerTurnLabel;
    QLabel *questionImageLabel;
    QLabel *questionTextLabel;
    QVBoxLayout *optionsLayout;
    QPushButton *optionAButton;
    QPushButton *optionBButton;
    QPushButton *optionCButton;
    QLabel *feedbackLabel;
    QPushButton *finishButton;
    QGroupBox *rankingGroup;
    QVBoxLayout *rankingLayout;
    QTableView *rankingTableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JuegoTurnos)
    {
        if (JuegoTurnos->objectName().isEmpty())
            JuegoTurnos->setObjectName("JuegoTurnos");
        JuegoTurnos->resize(500, 650);
        centralwidget = new QWidget(JuegoTurnos);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        questionGroup = new QGroupBox(centralwidget);
        questionGroup->setObjectName("questionGroup");
        questionLayout = new QVBoxLayout(questionGroup);
        questionLayout->setObjectName("questionLayout");
        playerTurnLabel = new QLabel(questionGroup);
        playerTurnLabel->setObjectName("playerTurnLabel");
        playerTurnLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        questionLayout->addWidget(playerTurnLabel);

        questionImageLabel = new QLabel(questionGroup);
        questionImageLabel->setObjectName("questionImageLabel");
        questionImageLabel->setEnabled(true);
        questionImageLabel->setMinimumSize(QSize(300, 200));
        questionImageLabel->setMaximumSize(QSize(300, 200));
        questionImageLabel->setScaledContents(true);
        questionImageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        questionLayout->addWidget(questionImageLabel);

        questionTextLabel = new QLabel(questionGroup);
        questionTextLabel->setObjectName("questionTextLabel");
        questionTextLabel->setWordWrap(true);

        questionLayout->addWidget(questionTextLabel);

        optionsLayout = new QVBoxLayout();
        optionsLayout->setObjectName("optionsLayout");
        optionAButton = new QPushButton(questionGroup);
        optionAButton->setObjectName("optionAButton");

        optionsLayout->addWidget(optionAButton);

        optionBButton = new QPushButton(questionGroup);
        optionBButton->setObjectName("optionBButton");

        optionsLayout->addWidget(optionBButton);

        optionCButton = new QPushButton(questionGroup);
        optionCButton->setObjectName("optionCButton");

        optionsLayout->addWidget(optionCButton);


        questionLayout->addLayout(optionsLayout);


        mainLayout->addWidget(questionGroup);

        feedbackLabel = new QLabel(centralwidget);
        feedbackLabel->setObjectName("feedbackLabel");
        feedbackLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        mainLayout->addWidget(feedbackLabel);

        finishButton = new QPushButton(centralwidget);
        finishButton->setObjectName("finishButton");

        mainLayout->addWidget(finishButton);

        rankingGroup = new QGroupBox(centralwidget);
        rankingGroup->setObjectName("rankingGroup");
        rankingLayout = new QVBoxLayout(rankingGroup);
        rankingLayout->setObjectName("rankingLayout");
        rankingTableView = new QTableView(rankingGroup);
        rankingTableView->setObjectName("rankingTableView");

        rankingLayout->addWidget(rankingTableView);


        mainLayout->addWidget(rankingGroup);

        JuegoTurnos->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JuegoTurnos);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 21));
        JuegoTurnos->setMenuBar(menubar);
        statusbar = new QStatusBar(JuegoTurnos);
        statusbar->setObjectName("statusbar");
        JuegoTurnos->setStatusBar(statusbar);

        retranslateUi(JuegoTurnos);

        QMetaObject::connectSlotsByName(JuegoTurnos);
    } // setupUi

    void retranslateUi(QMainWindow *JuegoTurnos)
    {
        JuegoTurnos->setWindowTitle(QCoreApplication::translate("JuegoTurnos", "Juego Multijugador", nullptr));
        questionGroup->setTitle(QCoreApplication::translate("JuegoTurnos", "Pregunta", nullptr));
        finishButton->setText(QCoreApplication::translate("JuegoTurnos", "Terminar Partida", nullptr));
        rankingGroup->setTitle(QCoreApplication::translate("JuegoTurnos", "Ranking", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JuegoTurnos: public Ui_JuegoTurnos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUEGOS_TURNOS_H
