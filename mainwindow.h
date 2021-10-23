#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QWidget>
#include <QList>
#include <Player.h>

class MainWindow: public QGraphicsView
{
public: // Funciones
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    MainWindow(QWidget * = nullptr);
    ~MainWindow();


public: // Variables
    Player* Player1;
    QGraphicsScene *Scene;
};
#endif // MAINWINDOW_H
