#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow* GameWindow::p_game = nullptr;

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    srand(uint(time(nullptr)));

    Scenes.reserve(10);
    ui->setupUi(this);
    Scenes.push_back(new QGraphicsScene(this));
    Scenes.push_back(new QGraphicsScene(this));
    Scenes.push_back(new QGraphicsScene(this));
    ui->graphicsView->setScene(Scenes[0]);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->centerOn(540, -360);

    Manager = new fmanager("Data.txt");

    PuccaTimer = new QTimer();
    connect(PuccaTimer, &QTimer::timeout, [=](){
        Player *p = new Player();
        p->SetPos((rand() % 1080), -200);
        Scenes[0]->addItem(p);
        p->starttimer(50);
    });
    PuccaTimer->start(5000);

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_W:{Players[0]->setTArea(0); return;}
        case Qt::Key_S:{Players[0]->setTArea(1); return;}
        case Qt::Key_A:{Players[0]->setVelocidad(-2, Players[0]->GetVelocidad().y); Players[0]->setTArea(2); return;}
        case Qt::Key_D:{Players[0]->setVelocidad(2, Players[0]->GetVelocidad().y); Players[0]->setTArea(2); return;}

        case Qt::Key_I:{Players[1]->setTArea(0); return;}
        case Qt::Key_K:{Players[1]->setTArea(1); return;}
        case Qt::Key_J:{Players[1]->setVelocidad(-1.2f, Players[1]->GetVelocidad().y); Players[1]->setTArea(2); return;}
        case Qt::Key_L:{Players[1]->setVelocidad(1.2f, Players[1]->GetVelocidad().y); Players[1]->setTArea(2); return;}
    }
}

void GameWindow::sEnableCollitions()
{
    CollitionsTimer = new QTimer();
    connect(CollitionsTimer, &QTimer::timeout, [=](){

        for(Player *P : Players){
            QList<QGraphicsItem *> P_CollidingItems = P->collidingItems();

            if(P_CollidingItems.size()){
                for(QGraphicsItem *i : P_CollidingItems){

                    //Player *player = dynamic_cast<Player *>(i);
                    Ninja *enemy = dynamic_cast<Ninja *>(i);
                    municion *bullet = dynamic_cast<municion *>(i);
                    Vidas *lifes = dynamic_cast<Vidas*>(i);

                    if(bullet || enemy){
                        if(!P->IsInmune()){

                            P->setLifes(P->getLifes() - 1);
                            P->InmunityStart(250);

                            if(bullet){
                                Scenes[1]->removeItem(bullet);
                                //bullet->Delete();
                            }
                            if(!P->getLifes()){

                                for(Ninja *E : Enemies){
                                    rfDC(E)->stoptimer2();
                                    rfDC(E)->setP(nullptr);
                                }
                                P->setCenter(false);
                                P->TimeStop();
                                Scenes[1]->removeItem(P);
                                //P->Die();
                                continue;
                            }

                            P->InmunityStart(250); // 250
                        }
                    }
                    else if(lifes){
                        Scenes[1]->removeItem(lifes);
                        lifes->~Vidas();
                        P->setLifes(P->getLifes()+1);
                        }/// Damage player
                }
            }
        }
    });
    CollitionsTimer->start(10);
}

void GameWindow::mEnableCollitions()
{
    CollitionsTimer = new QTimer();
    connect(CollitionsTimer, &QTimer::timeout, [=](){

        for(Player *P : Players){
            QList<QGraphicsItem *> P_CollidingItems = P->collidingItems();

            if(P_CollidingItems.size()){
                for(QGraphicsItem *i : P_CollidingItems){

                    //Player *player = dynamic_cast<Player *>(i);
                    Ninja *enemy = dynamic_cast<Ninja *>(i);
                    municion *bullet = dynamic_cast<municion *>(i);
                    Vidas *lifes = dynamic_cast<Vidas*>(i);

                    if(bullet || enemy){
                        if(!P->IsInmune()){

                            P->setLifes(P->getLifes() - 1);
                            P->InmunityStart(250);

                            if(bullet){
                                Scenes[2]->removeItem(bullet);
                                //bullet->Delete();
                            }
                            if(!P->getLifes()){

                                for(Ninja *E : Enemies){
                                    rfDC(E)->stoptimer2();
                                    rfDC(E)->setP(nullptr);
                                }

                                P->setCenter(false);
                                P->TimeStop();
                                Scenes[2]->removeItem(P);
                                if(Players[0] == P){
                                    Players[1]->setCenter(true);
                                }
                                else if(Players[1] == P){
                                    Players[0]->setCenter(true);
                                }


                                //P->Die();
                                continue;
                            }

                            //P->InmunityStart(250); // 250
                        }
                    }
                    else if(lifes){
                        Scenes[2]->removeItem(lifes);
                        lifes->~Vidas();
                        P->setLifes(P->getLifes()+1);
                        }/// Damage player
                }
            }
        }
    });
    CollitionsTimer->start(10);
}

GameWindow *GameWindow::getpointer(){return p_game;}

void GameWindow::on_SinglePlayer_clicked()
{
    ui->SinglePlayer->hide();
    ui->MultiPlayer->hide();
    ui->Scoreboard->hide();
    ui->Exit->hide();
    ui->label->hide();
    ui->label_2->hide();

    ui->graphicsView->setScene(Scenes[1]);
    Scenes[1]->setSceneRect(0, 0, 1080, 10000);

    Players.push_back(new Player());
    Players[0]->setPos(400,10);
    Scenes[1]->addItem(Players[0]);
    Players[0]->starttimer(100);
    Players[0]->setCenter(true);

    ui->graphicsView->ensureVisible(Players[0]);


    Shuriken *enemigo;
    enemigo= new Shuriken(400,0,0);
    Scenes[1]->addItem(enemigo);
    enemigo->setP(Players[0]);
    enemigo->starttimer(100);
    enemigo->starttimer2(3000);

    enemigo= new Shuriken(500,900,0);
    Scenes[1]->addItem(enemigo);
    enemigo->setP(Players[0]);
    enemigo->starttimer(100);
    enemigo->starttimer2(2000);

    Scenes[1]->addItem(new Vidas(500,750));
    Scenes[1]->addItem(new Vidas(250,1500));
    Scenes[1]->addItem(new Vidas(375,2250));

    Score *score = new Score(1,"Puntaje: ",{0,0});
    score->setPos(score->x(), score->y());
    score->setP(Players[0]);
    Scenes[1]->addItem(score);
    score->starttimer(10);


    Score *vidas = new Score(0,"Vidas: ",{900,0});
    vidas->setPos(score->x(), score->y());
    vidas->setP(Players[0]);
    Scenes[1]->addItem(vidas);
    vidas->starttimer2(10);

    Players[0]->TimeStart(500);

    sEnableCollitions();

    p_game = this;
    //show();

}

void GameWindow::on_MultiPlayer_clicked()
{
    ui->SinglePlayer->hide();
    ui->MultiPlayer->hide();
    ui->Scoreboard->hide();
    ui->Exit->hide();
    ui->label->hide();
    ui->label_2->hide();

    ui->graphicsView->setScene(Scenes[2]);
    Scenes[2]->setSceneRect(0, 0, 1080, 10000);

    Players.push_back(new Player(true));
    Players[0]->setPos(250,10);
    Scenes[2]->addItem(Players[0]);
    Players[0]->starttimer(100);
    ui->graphicsView->ensureVisible(Players[0]);

    Players.push_back(new Player());
    Players[1]->setPos(550,10);
    Players[1]->setPixmap(QPixmap(":/Imagenes/abyo.png").scaled(QSize(150, 200)));
    Scenes[2]->addItem(Players[1]);
    Players[1]->starttimer(100);

    Shuriken *enemigo;
    enemigo= new Shuriken(400,0,0);
    Scenes[2]->addItem(enemigo);
    enemigo->setP(Players[0]);
    enemigo->starttimer(100);
    enemigo->starttimer2(3000);

    enemigo= new Shuriken(500,900,0);
    Scenes[2]->addItem(enemigo);
    enemigo->setP(Players[1]);
    enemigo->starttimer(100);
    enemigo->starttimer2(2000);

    enemigo= new Shuriken(500,rand() % 900,0);
    Scenes[2]->addItem(enemigo);
    enemigo->setP(Players[rand() % 1]);
    enemigo->starttimer(100);
    enemigo->starttimer2(2000);

    Scenes[2]->addItem(new Vidas(500,750));
    Scenes[2]->addItem(new Vidas(250,1500));
    Scenes[2]->addItem(new Vidas(375,2250));

    Score *score = new Score(1,"Puntaje: ",{0,0});
    score->setPos(score->x(), score->y());
    score->setP(Players[0]);
    Scenes[2]->addItem(score);
    score->starttimer(10);

    score = new Score(1,"Puntaje: ",{0,100});
    score->setPos(score->x(), score->y() + 100);
    score->setP(Players[1]);
    Scenes[2]->addItem(score);
    score->starttimer(10);


    Score *vidas = new Score(0,"Vidas: ",{720,0});
    vidas->setPos(score->x(), score->y());
    vidas->setP(Players[0]);
    Scenes[2]->addItem(vidas);
    vidas->starttimer2(10);

    vidas = new Score(0,"Vidas: ",{720,100});
    vidas->setPos(score->x(), score->y() + 100);
    vidas->setP(Players[1]);
    Scenes[2]->addItem(vidas);
    vidas->starttimer2(10);

    Players[0]->TimeStart(500);
    Players[1]->TimeStart(500);

    mEnableCollitions();

    p_game = this;
}

void GameWindow::on_Scoreboard_clicked()
{

}

Q_NORETURN void GameWindow::on_Exit_clicked()
{
    Manager->SaveData();
    exit(1);
}
