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

    void setGravedad(float value);
    void setVelocidad(float value);
    void setAceleracion(float value);
    void setMunicion(const string &value);
    void setImagen(const string &value);

    float getGravedad() const;
    float getVelocidad() const;
    float getAceleracion() const;
    string getMunicion() const;
    string getImagen() const;

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
    Shuriken(int distancia, double x, double y,QGraphicsItem* = nullptr);
    ~Shuriken();
    void starttimer(int);
    void stoptimer();

    void starttimer2(int);
    void stoptimer2();

    void morir();
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

    int distancia;



};


#endif // ENEMIGOS_H
