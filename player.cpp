#include "player.h"

Player::Player(std::string name, double vit, int px, int py, int w, int h, int life, int cad, sf::Image *collision)
    : Entite(name,vit,px,py,w,h,life){
    connect(&internalClock,SIGNAL(timeout()),this,SLOT(canShoot()));
    internalClock.setInterval(cad);
    internalClock.start();
    connect(&invincibilityTimer,SIGNAL(timeout()),this,SLOT(stopInv()));
    invincibilityTimer.setInterval(1000);
    collision_map = collision;
}

void Player::move(){
    //TODO ou pas
}


//******/SLOTS\*******\\

void Player::left(){
    addX(-vitesse);
    if(tz.intersection(collision_map,sf::Color::Black))
        addX(vitesse);
    currentFrame++;
//    updateAngle(mousePosX,mousePosY);
}

void Player::right(){
    addX(vitesse);
    if(tz.intersection(collision_map,sf::Color::Black))
        addX(-vitesse);
    currentFrame++;
//    updateAngle(mousePosX,mousePosY);

}

void Player::up(){
    addY(-vitesse);
    if(tz.intersection(collision_map,sf::Color::Black))
        addY(vitesse);
    currentFrame++;
//    updateAngle(mousePosX,mousePosY);

}

void Player::down(){
    addY(vitesse);
    if(tz.intersection(collision_map,sf::Color::Black))
        addY(-vitesse);
    currentFrame++;
//    updateAngle(mousePosX,mousePosY);

}


void Player::updateAngle(int mouseX,int mouseY){
    mousePosX = mouseX;
    mousePosY = mouseY;
    angle = calcAngle(x,y,mouseX,mouseY);
    std::cout << angle << std::endl;
}

void Player::stopInv(){
    invincible = false;
    invincibilityTimer.stop();
    nom = "Hero";
}

void Player::invincibility(bool b){
    invincible = b;
    if(b)
        invincibilityTimer.start();
}

//**********************\\
