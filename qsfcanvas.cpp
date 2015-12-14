#include "qsfcanvas.h"


QSFcanvas::QSFcanvas(const QPoint& Position, const QSize& Size, QWidget* parent)
    : Qsfml(parent, Position, Size){
}





void QSFcanvas::keyPressEvent(QKeyEvent *Event){
    if(Event->key() == Qt::Key_Z || Event->key() == Qt::Key_Up){
        upPressed = true;
    }
    if(Event->key() == Qt::Key_S || Event->key() == Qt::Key_Down){
        downPressed = true;
    }
    if(Event->key() == Qt::Key_Q || Event->key() == Qt::Key_Left){
        leftPressed = true;
    }
    if(Event->key() == Qt::Key_D || Event->key() == Qt::Key_Right){
        rightPressed = true;
    }
}

void QSFcanvas::keyReleaseEvent(QKeyEvent *Event){
    if(Event->key() == Qt::Key_Z || Event->key() == Qt::Key_Up){
        upPressed = false;
    }
    if(Event->key() == Qt::Key_S || Event->key() == Qt::Key_Down){
        downPressed = false;
    }
    if(Event->key() == Qt::Key_Q || Event->key() == Qt::Key_Left){
        leftPressed = false;
    }
    if(Event->key() == Qt::Key_D || Event->key() == Qt::Key_Right){
        rightPressed = false;
    }
    if(Event->key() == Qt::Key_Space){
        emit setPause();
        pause();
    }
}

void QSFcanvas::mouseMoveEvent(QMouseEvent *Event){
    if(alive)
        emit sendMousePos(Event->x(),Event->y());
}

void QSFcanvas::mousePressEvent(QMouseEvent *Event){
    if(Event->button() == Qt::LeftButton){
        isShooting = true;
    }
}

void QSFcanvas::mouseReleaseEvent(QMouseEvent *Event){
    if(Event->button() == Qt::LeftButton){
        isShooting = false;
    }
}

void QSFcanvas::OnInit(){

    setMouseTracking(true);
    DM.init(*this,TM);



    //*Initialisation des images
    AM.add("Hero",AnimatedSprite(TM,"graphisme/roll",8,15*TAILLE,3,2,16));
    AM.add("HeroWounded",AnimatedSprite(TM,"graphisme/rollred",8,15*TAILLE,3,2,16));
    AM.add("heroMort",AnimatedSprite(TM,"graphisme/mort",1,30*TAILLE,true,16));
    AM.add("bullet",AnimatedSprite(TM,"graphisme/Projectile",1,3*TAILLE,true,16));
    AM.add("towerBullet",AnimatedSprite(TM,"graphisme/balletourelle",1,6*TAILLE,true,16));
    AM.add("boule",AnimatedSprite(TM,"graphisme/anim1c",9,7*TAILLE,true,16));
    AM.add("vie",AnimatedSprite(TM,"graphisme/rouge",1,5*TAILLE,true,16));
    AM.add("timer",AnimatedSprite(TM,"graphisme/gris",1,5*TAILLE,true,16));
    AM.add("bouleMort",AnimatedSprite(TM,"graphisme/mobsdeath",7,15*TAILLE,true,16));
    AM.add("towerBase",AnimatedSprite(TM,"graphisme/socletourelle",1,25*TAILLE,2,3,16));
    AM.add("towerCanon",AnimatedSprite(TM,"graphisme/canontourelle",3,25*TAILLE,2,3,16));
//    AM.add("towerCanonInFire",AnimatedSprite(TM,"graphisme/canontourelleinfire",1,25*TAILLE,2,3,16));
    //*/

    AM.get("vie").setPosition(200,10);
    AM.get("timer").setPosition(600,10);


    std::cout << "init!!!!" << std::endl;


}

void QSFcanvas::updateVie(int l){
    AM.get("vie").resize(3*l,20);
}
void QSFcanvas::updateTimer(int l){
    AM.get("timer").resize(l/300,20);
}
void QSFcanvas::receiveEM(QMap<int,Entite*>& em){
    DM.setEM(em);
}

void QSFcanvas::dispEvent(std::string str, int x, int y){
    DM.addAnim(str,x,y);
}

void QSFcanvas::pause(){
    if(myTimer.isActive())
        myTimer.stop();
    else myTimer.start();
}



void QSFcanvas::initView(int x, int y,int width,int height){
    sf::Vector2f viewCenter(x,y);
    sf::Vector2f viewSize(width,height);
    view = sf::View(viewCenter,viewSize);
}

void QSFcanvas::heroDeath(){
    alive = false;
}

void QSFcanvas::OnUpdate()
{
    if(alive){
        if(leftPressed)
            emit turnLeft();
        if(rightPressed)
            emit turnRight();
        if(upPressed)
            emit turnUp();
        if(downPressed)
            emit turnDown();
        if(isShooting)
            emit sigShoot(1);
    }/*else ((QWidget*)this)->close();*/

    clear();

    setView(view);

    DM.display(AM,*this);

    AM.get("vie").affichage(*this);
    AM.get("timer").affichage(*this);
}

ImageManager& QSFcanvas::getIM(){
    return IM;
}
