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

    Player(bool IsCenter = false, QGraphicsItem* = nullptr);// recibe una direccion de memoria(siempre va)
    ~Player();

    void starttimer(int);
    void stoptimer();
    void TimeStart(int);
    void TimeStop();

    void setTiempo(double t);
    void setGravedad(double g);
    void setAceleracion(double ax,double ay);
    void setVelocidad(double vx,double vy);
    void setBalas(uint b);
    void setTArea(const uchar &type);
    void setCenter(const bool &IsCenter);
    void setInmunity(const bool &value);
    void setLifes(const uint &value);
    void setRemainingTime(double);
    void setScore(const uint &value);
    void SetPos(double x, double y);

    bool IsInmune() const;
    void InmunityStart(int);
    void InmunityStop();

    uint getLifes() const;
    double getTArea() const;
    double GetTiempo();
    double GetGravedad();
    uint getScore() const;

    P::pair<double> GetAceleracion();
    P::pair<double> GetVelocidad();
    int GetBalas();

public slots://crea tipo vacios

    void Move();
    void Inmunity();
    void LimitTime();

private:

    QTimer* Timed;
    QTimer *InmunityTimer;
    QTimer *TimeTimer;

    P::pair<double> Velocidad;
    P::pair<double> Aceleracion;
    double Tiempo;
    double Gravedad;
    double arrastre, Mass;
    double y_0;
    double densidad;
    bool Center;

    uint Score;
    uint Balas;

    uchar TArea;
    uchar Lifes;

    bool Inmune;
};

#endif // PLAYER_H
