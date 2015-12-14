#ifndef BULLET_H
#define BULLET_H
#include "entite.h"

class Bullet : public Entite
{
    Q_OBJECT

public:
    Bullet(){}
    Bullet(std::string name, double vit, int px, int py, int w, int h, int deg, double angle,std::string par);
    Bullet(const Bullet& b)
        : damage(b.damage)
        , shooted(b.shooted)
        , parent(b.parent)
        , Entite(b)
    {}

    void move();

    std::string getParent();

private:
    int damage;
    bool shooted;
    std::string parent;

};

#endif // BULLET_H
