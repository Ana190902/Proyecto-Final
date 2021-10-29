#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <utilidades.h>
#include <Player.h>


class Score: public QGraphicsTextItem
{
    Q_OBJECT
public:

    Score(int choosed,std::string texto1,P::pair<int>coordenadas,QGraphicsTextItem * = nullptr);
    ~Score();

    void starttimer(int);
    void stoptimer();

    void starttimer2(int);
    void stoptimer2();

    void IncreaseScore();
    void setP(Player *value);

    int getScore();
private:
    QTimer *Timew;
    QTimer *Timew2;
    QTimer *InmunityTimer;
    QTimer *TimeTimer;

    Player* Player1;

    P::pair<int> coordenadas;
    int choose;

    std::string texto;

    uchar Lifes;

    bool Inmune;

    uint Score0;

public slots:
    void UpdatePos();
    void IncreaseOverTime();
};

#endif // SCORE_H
