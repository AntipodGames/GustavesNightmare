#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <QObject>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QPoint>
#include "displaymanager.h"
#include "datamanager.h"
#include "texturemanager.h"
#include "player.h"
#include "bullet.h"
#include "mob.h"
#include "boost/random.hpp"
#define TIMER 16
#define WAVETIMER 20
#define POPTIME0 2000


typedef struct envTime{
    int minute;
    int second;
    int centSec;
}envTime;

envTime convertTime(int);

QString timeToString(envTime);

class Environment : public QObject
{
    Q_OBJECT

public:
    Environment(){}
    Environment(int width, int height);

    void init();

    Player *getHero();

    void set_ai_mode(bool b){is_ai = b;}

public slots:
    void run();
    void pause();
    void shoot(int ID);
    void canShoot();
    void waves();
    void killMob(int ID);


signals:
    void sendEM(QMap<int,Entite*>&);
    void sendMort();
    void sendScore(int);
    void sendTime(envTime);
    void sendTotalTime(envTime);
    void sendLife(int);
    void sendTimer(int);
    void playerWounded(bool);

    void send_info_to_ai(const QMap<int, Entite*>& entity_map,
                         const QMultiMap<std::string,int>& entity_type_map,
                         const Player& player );

    void display(std::string,int,int);

    void chgMusic(QString);

    void mobDeath(int,int);

private:

    /*internal Functions*/
    void moveBullets();
    void moveMobs();
    bool shootedMob(Entite *);
    /********************/


    typedef std::pair<int,int> bpoint;

    //Attributs
    ImageManager IM;
    TextureManager TM;

    QMap<QString,int> playerStat;

    QTimer timer;
    QTimer cadence;
    QTimer popTimer;
    QTime chrono;
    int totalTime; //milli second

    boost::random::mt19937 random;

    bool waitStart;
    bool isArrived = false;

    QMap<int,Entite*> entityMap;
    QMultiMap<std::string,int> entityTypeMap;

    int heroID;
    int width;
    int height;
    bool stop = false;
    DataManager dataLoader;

    bool allowToShoot  = true;
    sf::Sprite hitBox;

    bool is_ai = false;
};

#endif // ENVIRONMENT_H
