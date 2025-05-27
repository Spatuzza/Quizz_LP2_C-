#ifndef JUEGO_TURNOS_H
#define JUEGO_TURNOS_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include <QStandardItemModel>

namespace Ui { class JuegoTurnos; }

struct Pregunta {
    QString texto;
    QString imgBase64;
    QString opA;
    QString opB;
    QString opC;
    QString correcta;
    QString categoria;
};

class JuegoTurnos : public QMainWindow
{
    Q_OBJECT

public:
    explicit JuegoTurnos(QWidget *parent, const QStringList &players);
    ~JuegoTurnos();

signals:
    void gameFinished();

private slots:
    void on_optionAButton_clicked();
    void on_optionBButton_clicked();
    void on_optionCButton_clicked();
    void on_finishButton_clicked();

private:
    Ui::JuegoTurnos *ui;
    QVector<Pregunta> preguntas;
    QStandardItemModel *rankingModel;
    int playerCount;
    QStringList playerNames;
    QVector<int> scores;
    int currentPlayer;
    int questionIndex;

    void loadPreguntas();
    void showPregunta(int index);
    void updateRanking();
};

#endif
