#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow* MainWindow::p_game = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    view = new QGraphicsView(this);
    Scene = new QGraphicsScene(this);
    srand(unsigned(time(nullptr)));

    view->resize(1080,720);
    //resize();
    Scene->setSceneRect(0, 0, 1080, 10000); // (-960, -540, 960, 540);
    //setBackgroundBrush(QBrush(Qt::white));
    view->setBackgroundBrush(QBrush(QImage(":/Imagenes/Fondo.jfif")));
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setScene(Scene);

    Player1 = new Player();
    Player1->setPos(400,10);
    Scene->addItem(Player1);
    Player1->starttimer(100);
    Player1->setCenter(true);

    view->ensureVisible(Player1);


    Player2 = new Player();
    Player2->setPos(400,10);
    Player2->setPixmap(QPixmap(":/Imagenes/abyo.png").scaled(QSize(150, 200)));
    Scene->addItem(Player2);
    Player2->starttimer(100);


    Shuriken1= new Shuriken(0,0);
    Scene->addItem(Shuriken1);
    Shuriken1->setP(Player1);
    Shuriken1->starttimer(100);
    Shuriken1->starttimer2(1000);

    Shuriken1= new Shuriken(720,0);
    Scene->addItem(Shuriken1);
    Shuriken1->setP(Player1);
    Shuriken1->starttimer(100);
    Shuriken1->starttimer2(1000);

    p_game = this;
    show();


}

MainWindow::~MainWindow()
{
}

void MainWindow::mousePressEvent(QMouseEvent *event){return;}
void MainWindow::mouseMoveEvent(QMouseEvent *event){return;}

//Movimiento fisico: cambio de area transversal para que tenga resistencia al aire
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A){
        Player1->setVelocidad(-3, Player1->GetVelocidad().y);
        Player1->setTArea(2);
    }
    else if(event->key()==Qt::Key_D){
        Player1->setVelocidad(3,Player1->GetVelocidad().y);
        Player1->setTArea(2);
    }   
    else if(event->key()==Qt::Key_W){
        Player1->setTArea(0);
    }
    else if(event->key()==Qt::Key_S){
        Player1->setTArea(1);
    }

    //segundo jugador
    else if(event->key()==Qt::Key_J){
        Player2->setVelocidad(-3, Player2->GetVelocidad().y);
        Player2->setTArea(2);
    }
    else if(event->key()==Qt::Key_L){
        Player2->setVelocidad(3,Player2->GetVelocidad().y);
        Player2->setTArea(2);
    }
    else if(event->key()==Qt::Key_I){
        Player2->setTArea(0);
    }
    else if(event->key()==Qt::Key_K){
        Player2->setTArea(1);
    }


}

MainWindow *MainWindow::getpointer()
{
    return p_game;
}


