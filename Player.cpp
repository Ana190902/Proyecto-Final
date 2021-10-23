#include <Player.h>

Player::Player(QGraphicsItem* parent){
    setPixmap(QPixmap(":/Imagenes/Pucca.png").scaled(QSize(100, 100)));
    Timed = new QTimer();
    connect(Timed,SIGNAL(timeout()),this,SLOT(Move()));
    Gravedad=0;

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

void Player::setGravedad(float g)
{
    Gravedad = g;

}

void Player::setAceleracion(float ax, float ay)
{
        Aceleracion.x = ax;
        Aceleracion.y = ay;

}

void Player::setVelocidad(float vx, float vy)
{
    Velocidad.x = vx;
    Velocidad.y = vy;

}

void Player::setBalas(uint b)
{
    Balas = b;

}

double Player::GetTiempo()
{
    return Tiempo;

}

float Player::GetGravedad()
{
    return Gravedad;


}

pair<float> Player::GetAceleracion()
{
    return Aceleracion;


}

pair <float> Player::GetVelocidad()
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
    Aceleracion.y += Gravedad;
    Velocidad.x += Aceleracion.x;
    Velocidad.y += Aceleracion.y;
    Velocidad.x *= 0.97;
    setPos(x()+Velocidad.x,y()+Velocidad.y);
    Aceleracion = {0, Gravedad};

}

