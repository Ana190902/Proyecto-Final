#ifndef UTILIDADES_H
#define UTILIDADES_H
#include <QDebug>
#include <vector>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <math.h>

#define e 2.72
#define pi 3.14

namespace P{
    template <typename T>
    struct pair{ //
        T x,y;
    };
}
class IDs : public QGraphicsPixmapItem{
public:
    int ID;
    IDs(QGraphicsItem* parent=nullptr){

    }
    ~IDs()=default;
};





#endif // UTILIDADES_H
