#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

#include <ctime>

#include "fmanager.h"
#include "Player.h"
#include "enemigos.h"
#include "score.h"
#include "vidas.h"

#define rfDC(x) dynamic_cast<Shuriken*>(x)

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow() override;

    void keyPressEvent(QKeyEvent *event) override;
    void sEnableCollitions();
    void mEnableCollitions();
    static GameWindow *getpointer();

private slots:
    void on_SinglePlayer_clicked();
    void on_MultiPlayer_clicked();
    void on_Scoreboard_clicked();
    void on_Exit_clicked();

public:
    Ui::GameWindow *ui;
    QList<QGraphicsScene *> Scenes;
    QList<Player *> Players;
    QList<Ninja *> Enemies;
    //Vidas* vida;
    //Score* score;
    //Score* vidas;

    fmanager *Manager;
    QTimer* PuccaTimer;
    QTimer* CollitionsTimer;

private:
    static GameWindow* p_game;


};

#endif // GAMEWINDOW_H
