#include "score.h"
#include <QFont>
Score::Score(int choosed,std::string texto1,P::pair<int>coordenadas,QGraphicsTextItem *parent): QGraphicsTextItem(parent){

    texto=texto1;
    choose=choosed;

    this->coordenadas=coordenadas;
    setPlainText(QString(texto.c_str()) + QString::number(0));
    setDefaultTextColor(Qt::black);
    setFont(QFont("fantasy",16));
    Timew = new QTimer();
    connect(Timew,SIGNAL(timeout()),this,SLOT(UpdatePos()));
    Timew->start(100);


}
void Score::starttimer(int)
{

}
void Score::stoptimer()
{

}
void Score::starttimer2(int)
{

}
void Score::stoptimer2()
{

}
Score::~Score()
{

}
void Score :: IncreaseScore(){
    int score = 50;
    setPlainText(QString("Puntaje: ") + QString::number(0));
}
void Score :: IncreaseOverTime(){
    int score = 50;
    setPlainText(QString("Puntaje: ") + QString::number(0));
}
int Score::getScore(){return 0;}
void Score::setP(Player *value)
{
    Player1 = value;
}
void Score::UpdatePos()
{
    if(choose==1)
        setPlainText(QString(texto.c_str()) + QString::number(Player1->getScore()));
    else if(choose==0)
        setPlainText(QString(texto.c_str()) + QString::number(Player1->getLifes()));
    else;

    if((Player1->y()-350)<0){
        setPos(coordenadas.x,coordenadas.y);
    }
    else
        setPos(x(),Player1->y()-350);
}
