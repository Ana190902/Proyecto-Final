#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <utilidades.h>
#include <QGraphicsScene>

class Player : public QObject, public IDs {
    Q_OBJECT
public:

    void starttimer(int);
    void stoptimer();
    void setTiempo(double t);
    void setGravedad(double g);
    void setAceleracion(double ax,double ay);
    void setVelocidad(double vx,double vy);
    void setBalas(uint b);
    void setTArea(const uchar &type);
    void setCenter(const bool &IsCenter);


    double getTArea() const;
    double GetTiempo();
    double GetGravedad();
    P::pair<double> GetAceleracion();
    P::pair<double> GetVelocidad();
    int GetBalas();

    Player(bool IsCenter = false, QGraphicsItem* = nullptr);// recibe una direccion de memoria(siempre va)
    ~Player();



public slots://crea tipo vacios

    void Move();

private:

    QTimer* Timed;
    double Gravedad;
    P::pair<double> Velocidad;
    P::pair<double> Aceleracion;
    double Tiempo;
    uint Balas;
    double arrastre, Mass;
    double y_0;
    uchar TArea;
    double densidad;
    bool Center;


};

#endif // PLAYER_H
