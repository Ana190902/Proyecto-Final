#ifndef ENEMIGOS_H
#define ENEMIGOS_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <string.h>
#include <utilidades.h>
#include <municion.h>
#include <QGraphicsScene>

using namespace std;

class Ninja : public QObject,public IDs
{
public:
    Ninja();
    ~Ninja();

    float getGravedad() const;
    void setGravedad(float value);

    float getVelocidad() const;
    void setVelocidad(float value);

    float getAceleracion() const;
    void setAceleracion(float value);

    string getMunicion() const;
    void setMunicion(const string &value);

    string getImagen() const;
    void setImagen(const string &value);

private:
    float Gravedad;
    float Velocidad;
    float Aceleracion;
    string municion;
    string imagen;

};

class Shuriken : public Ninja
{
Q_OBJECT
public:
    void starttimer(int);
    void stoptimer();

    void starttimer2(int);
    void stoptimer2();

    void morir();


    Shuriken();
    ~Shuriken();
    Shuriken(double x, double y,QGraphicsItem* = nullptr);
    void setP(QGraphicsItem *value);

public slots:

    void move();
    void apuntar();

private:
    QTimer* Timed1;
    QTimer* Timed2;
    QGraphicsItem *P;
    double densidad;
    double LTArea, STArea, MTArea, Mass, arrastre;
    double y_0;



};


#endif // ENEMIGOS_H
