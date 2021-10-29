#include "mainwindow.h"
#include "ui_mainwindow.h"

//MainWindow* MainWindow::p_game = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    Manager = new fmanager("Data.txt");

    if(/*DISABLES CODE*/(false)){
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

        Players.push_back(new Player());
        Players[0]->setPos(400,10);
        Scene->addItem(Players[0]);
        Players[0]->starttimer(100);
        Players[0]->setCenter(true);

        view->ensureVisible(Players[0]);

    /*
        Players.push_back(new Player());
        Players[1]->setPos(400,10);
        Players[1]->setPixmap(QPixmap(":/Imagenes/abyo.png").scaled(QSize(150, 200)));
        Scene->addItem(Players[1]);
        Players[1]->starttimer(100);

    */
        Shuriken1= new Shuriken(400,0,0);
        Scene->addItem(Shuriken1);
        Shuriken1->setP(Players[0]);
        Shuriken1->starttimer(100);
        Shuriken1->starttimer2(3000);

        Shuriken1= new Shuriken(500,720,0);
        Scene->addItem(Shuriken1);
        Shuriken1->setP(Players[0]);
        Shuriken1->starttimer(100);
        Shuriken1->starttimer2(2000);

        vida= new Vidas(500,720);
        Scene->addItem(vida);

        score = new Score(1,"Puntaje: ",{0,0});
        score->setPos(score->x(), score->y());
        score->setP(Players[0]);
        Scene->addItem(score);
        score->starttimer(10);

        vidas = new Score(0,"Vidas: ",{720,0});
        vidas->setPos(score->x(), score->y());
        vidas->setP(Players[0]);
        Scene->addItem(vidas);
        vidas->starttimer2(10);

        //EnableCollitions();

        Players[0]->TimeStart(500);

        //p_game = this;
        show();

    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::mousePressEvent(QMouseEvent *event){return;}
void MainWindow::mouseMoveEvent(QMouseEvent *event){return;}

//Movimiento fisico: cambio de area transversal para que tenga resistencia al aire
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    RLWindow = new Register(true, this);
    RLWindow->show();
    this->hide();
}


