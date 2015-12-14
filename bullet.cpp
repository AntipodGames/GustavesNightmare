#include "bullet.h"

Bullet::Bullet(std::string name, double vit, int px, int py, int w, int h, int deg, double a, std::string par)
    : Entite(name,vit,px,py,w,h,1){
    damage = deg;
    shooted = false;
    angle = a;
    parent = par;
}



void Bullet::move(){
    addX(vitesse*cos(angle));
    addY(vitesse*sin(angle));
}

std::string Bullet::getParent(){
    return parent;
}
