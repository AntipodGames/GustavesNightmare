#include "mob.h"

Mob::Mob(std::string name, double vit, int px, int py, int w, int h, int life, int cad,int towerCad)
    : Entite(name,vit,px,py,w,h,life){
    connect(&internalClock,SIGNAL(timeout()),this,SLOT(canShoot()));
    internalClock.setInterval(cad);
    internalClock.start();
    connect(&clock,SIGNAL(timeout()),this,SLOT(reverseMove()));
    clock.start(towerCad);
    incrAngle= PI/64;
}

bool Mob::move(sf::Image* hitbox,QMap<int, Entite *> EM, int X, int Y){

    if(abs(x-X) + abs(y-Y) < 300 && allowToShoot){
        addX(vitesse*4*cos(angle));
        addY(vitesse*4*sin(angle));
        restartInternalClock();
        for(QMap<int,Entite*>::iterator it = EM.begin(); it != EM.end(); it++){
            if((tz.intersection(it.value()->get_trigger())
                && it.value()->getID() != ID
                && it.value()->getID() != 1
                && it.value()->get_nom().compare("bullet") != 0)){

                emit mobDeath(it.value()->getID());
                return true;

            }
        }
        if(tz.intersection(hitbox,sf::Color::Black)){
            float tmpangle = tz.intersectAngle(hitbox);
            angle = PI + 2.*tmpangle - angle;
            addX(vitesse*4*cos(angle));
            addY(vitesse*4*sin(angle));
        }

    }
    else{

        angle = calcAngle(x,y,X,Y);

        if(x < X){
            addX(vitesse);
            for(QMap<int,Entite*>::iterator it = EM.begin(); it != EM.end(); it++){
                if((tz.intersection(it.value()->get_trigger()) && it.value()->getID() != ID && it.value()->getID() != 1)
                        || tz.intersection(hitbox,sf::Color::Black)){
                    addX(-vitesse);
                    break;
                }
            }
        }
        if(x > X){
            addX(-vitesse);
            for(QMap<int,Entite*>::iterator it = EM.begin(); it != EM.end(); it++){
                if((tz.intersection(it.value()->get_trigger()) && it.value()->getID() != ID && it.value()->getID() != 1)
                        || tz.intersection(hitbox,sf::Color::Black)){
                    addX(vitesse);
                    break;
                }
            }
        }
        if(y < Y){
            addY(vitesse);
            for(QMap<int,Entite*>::iterator it = EM.begin(); it != EM.end(); it++){
                if((tz.intersection(it.value()->get_trigger()) && it.value()->getID() != ID && it.value()->getID() != 1)
                        || tz.intersection(hitbox,sf::Color::Black)){
                    addY(-vitesse);
                    break;
                }
            }
        }
        if(y > Y){
            addY(-vitesse);
            for(QMap<int,Entite*>::iterator it = EM.begin(); it != EM.end(); it++){
                if((tz.intersection(it.value()->get_trigger()) && it.value()->getID() != ID && it.value()->getID() != 1)
                        || tz.intersection(hitbox,sf::Color::Black)){
                    addY(vitesse);
                    break;
                }
            }
        }
    }
    currentFrame+=0.4;
    return false;



}

void Mob::reverseMove(){
    incrAngle=-incrAngle;
}

/*/SLOTS\*/
void Mob::updateLife(int life){
    vie += life;
}
