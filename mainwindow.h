#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QWidget>
#include <QList>
#include <Player.h>
#include <enemigos.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow
{
public: // Funciones
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    static MainWindow *getpointer();

    MainWindow(QWidget * = nullptr);
    ~MainWindow();


public: // Variables
    Player* Player1;
    Player* Player2;
    QGraphicsScene *Scene;
    QGraphicsView *view;
    Shuriken* Shuriken1;
    Ui::MainWindow *ui;

private:
    static MainWindow* p_game;
};
#endif // MAINWINDOW_H
