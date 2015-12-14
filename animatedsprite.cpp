#include "animatedsprite.h"
#include "QString"
#include "QTextStream"



AnimatedSprite::AnimatedSprite(){}

/**
 * Constructeur d'image animé
 * @brief AnimatedSprite::AnimatedSprite
 * @param IM
 * @param adr
 * @param nbrF
 * @param width
 * @param height
 * @param centreX
 * @param centreY
 */
AnimatedSprite::AnimatedSprite(TextureManager & TM, std::string adr,int nbrF,int size, int centreX, int centreY,int time)
{
    std::string imAdr(adr);
    imAdr.append(".png");
    std::string dataAdr(adr);
    dataAdr.append(".data");

    image.setTexture(*(TM.GetTexture(imAdr)));

    timer = time;
    frame = 1;
    cpt = 0;
    nbrFrame = nbrF;
    scale = size;

    image.setScale(((float)size*nbrFrame)/((float)image.getTexture()->getSize().x),
                   ((float)image.getTexture()->getSize().y)/((float)image.getTexture()->getSize().x)
                   *((float)size*nbrFrame)/((float)image.getTexture()->getSize().y));

    image.setOrigin(image.getTexture()->getSize().x/(centreX*nbrFrame),image.getTexture()->getSize().y/centreY);
    image.setTextureRect(sf::IntRect(0,0,image.getTexture()->getSize().x/nbrFrame,image.getTexture()->getSize().y));
   // dataAnalyser(width,dataAdr);

}
AnimatedSprite::AnimatedSprite(TextureManager & TM, std::string adr, int nbrF, int size, bool centrer, int time)
{
    std::string imAdr(adr);
    imAdr.append(".png");
    std::string dataAdr(adr);
    dataAdr.append(".data");

    image.setTexture(*(TM.GetTexture(imAdr)));

    timer = time;
    frame = 1;
    cpt = 0;
    nbrFrame = nbrF;
    scale = size;
    image.setTextureRect(sf::IntRect(0,0,image.getTexture()->getSize().x/nbrFrame,image.getTexture()->getSize().y));

    image.setScale(((float)size*nbrFrame)/((float)image.getTexture()->getSize().x),
                   ((float)image.getTexture()->getSize().y)/((float)image.getTexture()->getSize().x)
                   *((float)size*nbrFrame)/((float)image.getTexture()->getSize().y));
    if(centrer){
     //   if(nbrFrame == 1)
       //     image.SetCenter(0,image.GetImage()->GetHeight()/2);
       // else
        image.setOrigin(image.getTexture()->getSize().x/(2*(nbrFrame)),image.getTexture()->getSize().y/2);
    }
   // dataAnalyser(width,dataAdr);

}

/**
 * @brief AnimatedSprite::AnimatedSprite
 * @param as
 */
AnimatedSprite::AnimatedSprite(const AnimatedSprite & as){
    image = as.image;
    nbrFrame = as.nbrFrame;
    cpt = as.cpt;
    frame = as.frame;
    scale = as.scale;

}

void AnimatedSprite::affichage(sf::RenderWindow& App){
    App.draw(image);
}

sf::Vector2f AnimatedSprite::TransformToLocal(const sf::Vector2f & Pt){
    return TransformToLocal(Pt);
}

void AnimatedSprite::setFrame(int i){
    frame = i%nbrFrame+1;
    image.setTextureRect(sf::IntRect((image.getTexture()->getSize().x/nbrFrame)*(frame-1)
                                     ,0
                                     ,(image.getTexture()->getSize().x/nbrFrame)
                                     ,image.getTexture()->getSize().y));

}

int AnimatedSprite::getFrame(){
    return frame;
}

int AnimatedSprite::getNbrFrame(){
    return nbrFrame;
}

void AnimatedSprite::Rotate(float angle){
    image.rotate(angle/PI*180);

}

void AnimatedSprite::setAngle(float angle){
    image.setRotation(angle/PI*180);
}

float AnimatedSprite::getAngle(){
    return image.getRotation()/180*PI;
}

void AnimatedSprite::setPosition(int x, int y){
    image.setPosition(x,y);
}

sf::Sprite& AnimatedSprite::getImage(){
    return image;
}

int AnimatedSprite::getScale(){
    return scale;
}

void AnimatedSprite::resize(int x, int y){
    image.setScale((float)(x*nbrFrame)/((float)image.getTexture()->getSize().x)
                   ,((float)y)/((float)image.getTexture()->getSize().y));
}
