#include "enemigos.h"
#define PS 30
Ninja::Ninja()
{

}
Ninja::~Ninja(){

}


float Ninja::getGravedad() const
{
    return Gravedad;
}

void Ninja::setGravedad(float value)
{
    Gravedad = value;
}

float Ninja::getVelocidad() const
{
    return Velocidad;
}

void Ninja::setVelocidad(float value)
{
    Velocidad = value;
}

float Ninja::getAceleracion() const
{
    return Aceleracion;
}

void Ninja::setAceleracion(float value)
{
    Aceleracion = value;
}

string Ninja::getMunicion() const
{
    return municion;
}

void Ninja::setMunicion(const string &value)
{
    municion = value;
}

string Ninja::getImagen() const
{
    return imagen;
}

void Ninja::setImagen(const string &value)
{
    imagen = value;
}

Shuriken::Shuriken(double x, double y,QGraphicsItem* parent){

    setPixmap(QPixmap(":/Imagenes/ninjadef.png").scaled(QSize(100, 100)));
    setPos(x,y);
    Timed1 = new QTimer();
    Timed2 = new QTimer();
    connect(Timed1,SIGNAL(timeout()),this,SLOT(move()));
    connect(Timed2,SIGNAL(timeout()),this,SLOT(apuntar()));

    densidad = 1.2;
    arrastre = 0.82;
    Mass = 70;
    y_0 = this->y();
    LTArea = 0.6 * 1.65;
    MTArea = 0.5 * 0.8;
    STArea = 0.4 * 0.3;


    setGravedad(0.1);

    ID=000;
}

Shuriken::~Shuriken(){

}
void Shuriken::move()
{
    /*
    setAceleracion( getGravedad()+getGravedad());
    setVelocidad(getVelocidad()+ getAceleracion());
    setPos(x(),y()+getVelocidad());
    setAceleracion(0);
    */
    double Distance = sqrt(pow((P->x() - this->x()), 2) + pow((P->y() - this->y()), 2));

        double K, Fa, Fw, Vf, ma;

        if(this->y() < P->y() && Distance > 100){
            K = (densidad * STArea * arrastre) / 2;
        }

        else if(this->y() > P->y() && Distance > 100){
            K = (densidad * LTArea * arrastre) / 2;

        }
        else{
            K = (densidad * MTArea * arrastre) / 2;
        }


        Fa = K * pow(getVelocidad() , 2);
        Fw = Mass * getGravedad();
        Vf = sqrt(Fw / K);
        ma = Fa - Fw;
        setAceleracion(ma / Mass);

        //qDebug() << QString::number(y());
        //qDebug() << QString::number(pow(e,((2 * getGravity())/(pow(Vf, 2)))*(y() - y_0)));
        double aux = ((pow(Vf, 2)) * pow(e,((2 * getGravedad())/(pow(Vf, 2)))*(y() - y_0)));

        setVelocidad((Vf * 3) <= pow(Vf, 2) + aux? (Vf * 3) : pow(Vf, 2) + aux);
        setPos(x(), y() + getVelocidad());

}

void Shuriken::apuntar()
{
    double Speedx, Speedy,Xori,Yori;
    Xori =  P->x() - this->x();
    Yori =  P->y() - this->y();
    if(Xori<0){
        Speedx = PS*-1;
        Speedy = (Yori*PS*-1)/Xori;
    }
    else{
        Speedx = PS;
        Speedy = (Yori*PS)/Xori;

    }


    class municion *d1=new class municion(Speedx, Speedy + this->getVelocidad(),111);
    d1->setPos(this->x(),this->y());
    scene()->addItem(d1);
    Speedx=0;
    Speedy=0;



}

void Shuriken::setP(QGraphicsItem *value)
{
    P = value;
}

void Shuriken::starttimer(int time)
{
    Timed1->start(time);

}

void Shuriken::stoptimer()
{
    Timed1->stop();

}

void Shuriken::starttimer2(int times)
{
    Timed2->start(times);

}

void Shuriken::stoptimer2()
{
    Timed2->stop();

}

void Shuriken::morir()
{
    this->~Shuriken();
}


