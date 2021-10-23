#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

template <typename T>
struct pair{ //
    T x,y;
};
class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:

    void starttimer(int);
    void stoptimer();
    void setTiempo(double t);
    void setGravedad(float g);
    void setAceleracion(float ax,float ay);
    void setVelocidad(float vx,float vy);
    void setBalas(uint b);

    double GetTiempo();
    float GetGravedad();
    pair<float> GetAceleracion();
    pair<float> GetVelocidad();
    int GetBalas();

    Player(QGraphicsItem* = nullptr);// recibe una direccion de memoria(siempre va)
    ~Player();

public slots://crea tipo vacios

    void Move();

private:

    QTimer* Timed;
    float Gravedad;
    pair<float> Velocidad;
    pair<float> Aceleracion;
    double Tiempo;
    uint Balas;


};

#endif // PLAYER_H
