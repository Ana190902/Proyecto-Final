#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    Scene = new QGraphicsScene();

    srand(unsigned(time(nullptr)));

    //resize(1080,720);
    //resize();
    Scene->setSceneRect(0, 0, 1080, 720); // (-960, -540, 960, 540);
    //setBackgroundBrush(QBrush(Qt::white));
    setBackgroundBrush(QBrush(QImage(":/Imagenes/Fondo.jfif")));

    setScene(Scene);

    Player1 = new Player();
    Scene->addItem(Player1);

    Player1->starttimer(100);

    show();
}

MainWindow::~MainWindow()
{
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_A){
        Player1->setAceleracion(-1,Player1->GetGravedad());
    }
    else if(event->key()==Qt::Key_D){
        Player1->setAceleracion(1,Player1->GetGravedad());
    }

}
void MainWindow::mousePressEvent(QMouseEvent *event){return;}
void MainWindow::mouseMoveEvent(QMouseEvent *event){return;}
