#ifndef QSFCANVAS_H
#define QSFCANVAS_H
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <QEvent>
#include <QMouseEvent>
//#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include "qsfml.h"
#include "imagemanager.h"
#include "environment.h"
#include "animatedmanager.h"
#include "displaymanager.h"
#include "stormblink.h"

class QSFcanvas : public Qsfml
{

    Q_OBJECT

public:
    QSFcanvas(const QPoint& Position, const QSize& Size,QWidget *parent = 0);

    ImageManager& getIM();

    void initView(int x, int y, int width, int height);


    DisplayManager* getDM(){
        return &DM;
    }

public slots :
    void pause();
    void receiveEM( QMap<int,Entite*>& em);
    void updateVie(int);
    void updateTimer(int);

    void heroDeath();

    void dispEvent(std::string, int x, int y);

signals:
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();
    void setPause();
    void sendMousePos(int,int);

    void sigShoot(int);

private:
    ImageManager IM;
    TextureManager TM;
    AnimatedManager AM;
    DisplayManager DM;

    sf::Clock Time;
    time_t initialTime;
    Carte carte;


    sf::View view;

    bool leftPressed = false;
    bool rightPressed = false;
    bool upPressed = false;
    bool downPressed = false;
    bool isShooting = false;
    bool alive = true;

    void OnInit();
    void OnUpdate();
    void keyPressEvent(QKeyEvent *Event);
    void keyReleaseEvent(QKeyEvent *Event);
    void mouseMoveEvent(QMouseEvent *Event);
    void mousePressEvent(QMouseEvent* Event);
    void mouseReleaseEvent(QMouseEvent* Event);


};

#endif // QSFCANVAS_H
