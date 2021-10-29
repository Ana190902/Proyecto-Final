#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QWidget>
#include <QList>

#include "score.h"
#include "vidas.h"
#include "Player.h"
#include "enemigos.h"
#include "fmanager.h"
#include "register.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
public: // Funciones
    MainWindow(QWidget * = nullptr);
    ~MainWindow() override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

public: // Variables
    Vidas* vida;
    Score* score;
    Score* vidas;
    QGraphicsScene *Scene;
    QGraphicsView *view;
    Shuriken* Shuriken1;
    QTimer* CollitionsTimer;
    QList<Player *> Players;
    QList<Ninja *> Enemies;
    fmanager *Manager;
    Ui::MainWindow *ui;
    Register *RLWindow;


private:
    //static MainWindow* p_game;
};
#endif // MAINWINDOW_H
