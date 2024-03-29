#include "gamewindow.h"
#include "ui_gamewindow.h"
//#include "mainwindow.h"
#include <Player.h>

namespace Ui { class GameWindow;}



Player::Player(bool IsCenter, QGraphicsItem* parent){
    setPixmap(QPixmap(":/Imagenes/pucaperfecta.png").scaled(QSize(100, 100)));
    setFlag(QGraphicsItem::ItemIsFocusable);

    Timed = new QTimer();
    InmunityTimer = new QTimer();
    TimeTimer = new QTimer();

    connect(Timed,SIGNAL(timeout()),this,SLOT(Move()));
    connect(InmunityTimer,SIGNAL(timeout()),this,SLOT(Inmunity()));
    connect(TimeTimer,SIGNAL(timeout()),this,SLOT(LimitTime()));

    Gravedad=0.1;
    Center=IsCenter;
    ID=111;
    Aceleracion={0,0};
    Velocidad={0,0};
    arrastre=0.82;
    Mass=70;
    y_0=y();
    TArea=5;
    densidad=1.2;//densidad del aire a 30 grados
    Lifes = 3;
    Inmune = false;
    Tiempo = 30;
    Score=0;

}
void Player::starttimer(int times)
{
    Timed->start(times);
}

void Player::stoptimer()
{
    Timed->stop();
}

void Player::setTiempo(double t)
{
    Tiempo = t;
}

void Player::setGravedad(double g)
{
    Gravedad = g;
}

void Player::setAceleracion(double ax, double ay)
{
        Aceleracion.x = ax;
        Aceleracion.y = ay;
}

void Player::setVelocidad(double vx, double vy)
{
    Velocidad.x = vx;
    Velocidad.y = vy;
}

void Player::setBalas(uint b)
{
    Balas = b;
}

void Player::setTArea(const uchar &type)
{
    TArea=type;
}
double Player::getTArea() const
{
    switch (TArea) {
        case 0: return 0.80 * 1.85;     // Max Transversal Area
        case 1: return 0.55 * 0.35;     // Short Transversal Area
        case 2: return 0.75 * 1.40;     // Medium Transversal Area
        default: return 0.75 * 1.70;    // Long Transversal Area
    }
}
double Player::GetTiempo()
{
    return Tiempo;
}

double Player::GetGravedad()
{
    return Gravedad;
}

P::pair<double> Player::GetAceleracion()
{
    return Aceleracion;
}

P::pair <double> Player::GetVelocidad()
{
    return Velocidad;
}

int Player::GetBalas()
{
    return Balas;
}

Player::~Player()
{

}
void Player::Move()
{
    /*
    Aceleracion.y += Gravedad;
    Velocidad.x += Aceleracion.x;
    Velocidad.y += Aceleracion.y;
    Velocidad.x *= 0.97;
    setPos(x()+Velocidad.x,y()+Velocidad.y);

    MainWindow* mw = MainWindow::getpointer();
    mw->view->centerOn(x(),y());
    scene()->setFocusItem(this);
    Aceleracion = {0, Gravedad};
    qDebug()<<QString::number(x());
    qDebug()<<QString::number(y());
    */
    double K, Fa, Fw, Vf, ma;

        K = (densidad * getTArea() * arrastre) / 2;
        Fa = K * pow(GetVelocidad().y , 2);
        Fw = Mass * GetGravedad();
        Vf = sqrt(Fw / K);
        ma = Fa - Fw;
        setAceleracion(GetAceleracion().x, ma / Mass);

        //qDebug() << QString::number(getTArea());
        //qDebug() << QString::number(K);
        //qDebug() << QString::number(Vf);
        //qDebug() << QString::number(pow(e,((2 * getGravity())/(pow(Vf, 2)))*(y() - y_0)));
        double aux = ((pow(Vf, 2)) * pow(euler,((2 * GetGravedad())/(pow(Vf, 2)))*(y() - y_0)));
        double aux2 = pow(Vf, 2) + aux;

        setVelocidad(GetVelocidad().x * 0.97,
                 (Vf * 3) <= aux2? (Vf * 3) : aux2);

        //qDebug() << QString("Velocidad: ") << QString::number((Vf * 4) <= (pow(Vf, 2) + aux)? (Vf * 4) : pow(Vf, 2) + aux);

        setPos(x() + GetVelocidad().x,
               y() + GetVelocidad().y);

        //qDebug() << QString("Speed: ") << QString::number(getSpeed().second);
        //qDebug() << QString::number(y());

        //setAcceleration(getAcceleration() + getGravity());
        //
        //getSpeed() >= 1? setSpeed(1) : setSpeed(getSpeed() + getAcceleration());
        //
        //setPos(x(), y() + getSpeed());
        //
        //setAcceleration(0);

        //Acceleration.second += Gravity;
        //
        //Speed.first += Acceleration.first;
        //Speed.second += Speed.second >= 1? ((Speed.second - 1) * -1) : Acceleration.second;
        //Speed.second >= 1? Speed.second = 1 : 0;
        //
        //Speed.first *= 0.97;
        //
        //setPos(x() + Speed.first, y() + Speed.second);
        //
        if(Center){
            GameWindow *mw = GameWindow::getpointer();
            //mw->view->centerOn(x(), y());
            mw->ui->graphicsView->centerOn(x(), y());
            scene()->setFocusItem(this);
        }
        //Acceleration = {0, Gravity};
}
void Player::setCenter(const bool &value)
{
    Center = value;
}
void Player::Inmunity()
{
    static short Joins = 0;

    if(Joins == 12){
        InmunityStop();
        Joins = 0;

        /// Change pixmap
        switch(Lifes){

        case 3: break;
        case 2: break;
        case 1: break;

        }

        return;
    }
    Joins += 1;
}
uint Player::getLifes() const{return Lifes;}
bool Player::IsInmune() const{return Inmune;}
void Player::setInmunity(const bool &value){Inmune = value;}
void Player::setLifes(const uint &value){Lifes = value;}
void Player::InmunityStart(int msec){InmunityTimer->start(msec);}
void Player::InmunityStop(){InmunityTimer->stop();}
void Player::setScore(const uint &value){Score = value;}
void Player::SetPos(double x, double y){y_0 = y; setPos(x, y);}

uint Player::getScore() const{return Score;}
void Player::LimitTime()
{
    static short Joins = 0;

    Tiempo--;
    if(!Tiempo){
        //scene()->removeItem(this);
        //this->~Plasyer();
    }
    /// Shades image
    if(Joins % 2){
      Tiempo--;
      Score++;}
    ///
    else
      Score++;
    ///
    Joins += 1;
}

void Player::TimeStart(int msec){TimeTimer->start(msec);}
void Player::TimeStop(){TimeTimer->stop();}
