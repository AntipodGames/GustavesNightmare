#ifndef MOB_H
#define MOB_H
#include <QObject>
#include "entite.h"
#include <QMap>

class Mob : public Entite
{
    Q_OBJECT

public:
    Mob(){}
    Mob(std::string name, double vit, int px, int py, int w, int h, int life, int cad = 0, int towerCad = 0);

    bool move(sf::Image *, QMap<int,Entite*>, int, int);

    float getIncrAngle(){return incrAngle;}

    float getBaseAngle(){return baseAngle;}
    void setBaseAngle(float a){baseAngle = a;}

public slots:
    void updateLife(int life);
    void reverseMove();


signals:
    void mobDeath(int ID);

private :
    QTimer clock;
    float incrAngle;
    float baseAngle;

};

#endif // MOB_H
