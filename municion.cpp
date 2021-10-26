#include "municion.h"

municion::municion(double velocidadx,double velocidady, int ID1,QGraphicsItem *parent)
{
    velocidad.x=velocidadx;
    velocidad.y=velocidady;
    setPixmap(QPixmap(":/Imagenes/shuriken.png").scaled(QSize(50, 50)));
    timet = new QTimer();
    connect(timet,SIGNAL(timeout()),this,SLOT(move()));
    timet->start(100);
    ID=222;
    llegada=ID1;

}

municion::~municion(){

}

P::pair<double> municion::getVelocidad() const
{
    return velocidad;
}

void municion::setVelocidad(const P::pair<double> &value)
{
    velocidad = value;
}
void municion::move()
{

    setPos(x()+velocidad.x,y()+velocidad.y);
    velocidad.y *= 0.97;
    std::vector<QGraphicsItem* > Colliding_Item;

        for(auto I : collidingItems())
            Colliding_Item.push_back(I);

        for(int i = 0, n = Colliding_Item.size(); i < n; i++){
            IDs aux(Colliding_Item[i]);
            if(aux.ID == llegada){

                // Increase score
               // game->score->IncreaseScore();

                //Remove
                scene()->removeItem(Colliding_Item[i]);
                scene()->removeItem(this);
                //Delete
                delete Colliding_Item[i];
                delete this;

            }
        }

}

