#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <QVector>
#include <SFML/Graphics.hpp>
#include <texturemanager.h>
#include <QFile>
#include <stack>
#define PI 3.14159265359

class AnimatedSprite
{
public:
    AnimatedSprite();
    AnimatedSprite(TextureManager &TM, std::string adr, int nrbF, int size, int centreX, int centreY,int timer);
    AnimatedSprite(TextureManager& TM, std::string adr, int nbrF, int size,bool,int timer);
    AnimatedSprite(const AnimatedSprite&);

    void affichage(sf::RenderWindow&);
    void setFrame(int);
    int getFrame();
    void setPosition(int,int);
    sf::Sprite& getImage();
    void setAngle(float);
    float getAngle();
    void Rotate(float angle);
    int getScale();
    int getNbrFrame();
    void resize(int x, int y);

    static sf::Vector2f TransformToLocal(const sf::Vector2f &);


private:
    sf::Sprite image;

    int timer;
    int nbrFrame = 1;
    int frame = 0;
    int cpt;
    int scale;


};

#endif // ANIMATEDSPRITE_H
