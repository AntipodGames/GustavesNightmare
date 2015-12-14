#ifndef PLAYER_H
#define PLAYER_H
#include "entite.h"

class Player : public Entite
{    
    Q_OBJECT

public:
    Player(){}
    Player(std::string name, double vit, int px, int py, int w, int h, int life, int cad, sf::Image *collision);

    void move();

    bool isInvincible(){return invincible;}

public slots:
    void left();
    void right();
    void up();
    void down();
    void updateAngle(int mouseX, int mouseY);
    void invincibility(bool);
    void stopInv();
    void updateAngle(double a){angle = a;}

private:
    int mousePosX = 0;
    int mousePosY = 0;
    int invincible = false;
    QTimer invincibilityTimer;

    sf::Image* collision_map;
};

#endif // PLAYER_H
