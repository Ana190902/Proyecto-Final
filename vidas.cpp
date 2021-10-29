#include "vidas.h"

Vidas::Vidas(int x, int y, QGraphicsItem *)
{
    setPixmap(QPixmap(":/Imagenes/ramen.png").scaled(QSize(70, 50)));
    setPos(x,y);
}
