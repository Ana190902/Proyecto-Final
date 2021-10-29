#ifndef MUNICION_H
#define MUNICION_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <utilidades.h>
#include <Player.h>



class municion :  public QObject,public IDs
{
Q_OBJECT
public:
    municion(double velocidadx,double velocidady, int ID1 ,QGraphicsItem* = nullptr);
    ~municion();

    P::pair<double> getVelocidad() const;
    void setVelocidad( const P::pair<double> &value);

public slots:
     void move();

private:
    QTimer *timet;
    P::pair<double> velocidad;
    uint llegada;
};

#endif // MUNICION_H
