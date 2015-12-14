#include "environment.h"


Environment::Environment(int w, int h){

    hitBox.setTexture(*(TM.GetTexture("graphisme/collisionmap.png")));

    width = w;
    height = h;
    timer.setInterval(TIMER);


    playerStat.insert("mort",0);
    playerStat.insert("score",0);
    random.seed(time(NULL));

    chrono.start();

}

void Environment::init(){
    std::cout << "Environment Initialisation" << std::endl;

    Player* hero = new Player("Hero",7,400,300,20,20,100,500,IM.GetImage("graphisme/collisionmap.png"));
    entityMap.insert(hero->getID(),hero);
    heroID = hero->getID();

    waves();

    emit sendEM(entityMap);


    connect(&popTimer,SIGNAL(timeout()),this,SLOT(waves()));
    popTimer.start(POPTIME0);


    connect(&timer,SIGNAL(timeout()),this,SLOT(run()));
    timer.start();

    connect(this,SIGNAL(playerWounded(bool)),getHero(),SLOT(invincibility(bool)));


}

void Environment::canShoot(){
    allowToShoot = true;
    cadence.stop();
}

void Environment::run(){

    moveBullets();
    moveMobs();

    if(shootedMob(getHero()) && !getHero()->isInvincible()){
        getHero()->perdVie(2);
        emit playerWounded(true);
        getHero()->set_nom("HeroWounded");
    }


    //    if(getHero()->get_trigger().isColor2(hitBox,sf::Color::Black)){

    //    }

    //    std::cout << "num of mob " << entityTypeMap.values("boule").size() << std::endl;
    //    std::cout << "num of entity " << entityMap.size() << std::endl;


    if(getHero()->getVie() <= 0){
        getHero()->set_nom("heroMort");
        emit sendMort();
        timer.stop();
        popTimer.stop();

    }


    emit sendLife(getHero()->getVie());

    emit sendEM(entityMap);
    int tmp = POPTIME0/WAVETIMER;
    emit sendTimer(POPTIME0*tmp - WAVETIMER*(tmp*(tmp-1)/2) -chrono.elapsed());

    if(is_ai)
        emit send_info_to_ai(entityMap,entityTypeMap,*(getHero()));
}

void Environment::pause(){

    //--------------------------------------------//
    //TO DO : generalise la pause a tout les QTimer.
    //--------------------------------------------//

    if(timer.isActive()){
        timer.stop();
        popTimer.stop();
    }
    else{
        timer.start();
        popTimer.start();
    }
}


void Environment::shoot(int ID){
    std::string bulletName = "bullet";
    int velocity = 14;
    int px =entityMap.value(ID)->get_x()
            + ((double) entityMap.value(ID)->get_trigger().get_rayon())
            *cos(entityMap.value(ID)->getAngle()) ;
    int py = entityMap.value(ID)->get_y()
            + ((double) entityMap.value(ID)->get_trigger().get_rayon())
            *sin(entityMap.value(ID)->getAngle());
    if(entityMap.value(ID)->get_nom().compare("towerCanon")==0){
        bulletName = "towerBullet";
        velocity = 7;
    }
    if(entityMap.value(ID)->AllowToShoot()){
        Bullet* newBullet = new Bullet(bulletName
                                       ,velocity
                                       ,px
                                       ,py
                                       ,10,10
                                       ,50
                                       ,entityMap.value(ID)->getAngle()
                                       ,entityMap.value(ID)->get_nom());
        entityMap.insert(newBullet->getID(),newBullet);
        entityTypeMap.insertMulti(newBullet->get_nom(),newBullet->getID());
        entityMap.value(ID)->switchAllowToShoot(false);
        entityMap.value(ID)->restartInternalClock();
    }
}


void Environment::moveBullets(){
    for(int i = 0
        ;i < entityTypeMap.values("bullet").size()
        ;i++){
        ((Bullet*) entityMap.value(entityTypeMap.values("bullet")[i]))->move();
        if(((Bullet*) entityMap.value(entityTypeMap.values("bullet")[i]))->get_x() < 0
                || ((Bullet*) entityMap.value(entityTypeMap.values("bullet")[i]))->get_x() > width
                || ((Bullet*) entityMap.value(entityTypeMap.values("bullet")[i]))->get_y() < 0
                || ((Bullet*) entityMap.value(entityTypeMap.values("bullet")[i]))->get_y() > height){
            entityMap.remove(entityTypeMap.values("bullet")[i]);
            entityTypeMap.remove("bullet",entityTypeMap.values("bullet")[i]);
        }
    }
    for(int i = 0
        ;i < entityTypeMap.values("towerBullet").size()
        ;i++){
        ((Bullet*) entityMap.value(entityTypeMap.values("towerBullet")[i]))->move();
        if(((Bullet*) entityMap.value(entityTypeMap.values("towerBullet")[i]))->get_x() < 0
                || ((Bullet*) entityMap.value(entityTypeMap.values("towerBullet")[i]))->get_x() > width
                || ((Bullet*) entityMap.value(entityTypeMap.values("towerBullet")[i]))->get_y() < 0
                || ((Bullet*) entityMap.value(entityTypeMap.values("towerBullet")[i]))->get_y() > height){
            entityMap.remove(entityTypeMap.values("towerBullet")[i]);
            entityTypeMap.remove("towerBullet",entityTypeMap.values("towerBullet")[i]);
        }
    }

}

void Environment::moveMobs(){

    for(QMap<std::string,int>::iterator it = entityTypeMap.begin()
        ;it != entityTypeMap.end()
        ;it++){

        if(it.key().compare("boule") == 0){
            if(((Mob*) entityMap.value(it.value()))->move(IM.GetImage("graphisme/collisionmap.png"),entityMap,getHero()->get_x(),getHero()->get_y())
                    || shootedMob(entityMap.value(it.value()))
                    || getHero()->get_trigger().intersection(((Mob*) entityMap.value(it.value()))->get_trigger())){

                if(getHero()->get_trigger().intersection(((Mob*) entityMap.value(it.value()))->get_trigger())){
                    if(!getHero()->isInvincible()){
                        getHero()->perdVie(entityMap.value(it.value())->getVie());
                        emit playerWounded(true);
                        getHero()->set_nom("HeroWounded");
                    }
                }

                killMob(it.value());

            }
        }
        else if(it.key().compare("towerCanon")==0){

//            if(entityMap.value(it.value())->getAngle() <= )
            entityMap.value(it.value())->setAngle(entityMap.value(it.value())->getAngle()+((Mob*) entityMap.value(it.value()))->getIncrAngle());

            entityMap.value(it.value())->incrFrame(0.2);

            shoot(it.value());

            if(shootedMob(entityMap.value(it.value()))){
                    entityMap.value(it.value())->perdVie(10);

                if(entityMap.value(it.value())->getVie() <= 0)
                    killMob(it.value());

            }
        }

    }
}

void Environment::killMob(int ID){
    emit display("bouleMort",entityMap.value(ID)->get_x()
                 ,entityMap.value(ID)->get_y());
    emit mobDeath(entityMap.value(ID)->get_x(),
                  entityMap.value(ID)->get_y());
    entityTypeMap.remove(entityMap.value(ID)->get_nom(),ID);
    entityMap.remove(ID);


}

void Environment::waves(){

    if(popTimer.interval() > 200){
        boost::random::uniform_int_distribution<> gen(0,3);
        boost::random::uniform_int_distribution<> gen2(0,30);

        int x,y;
        double angle;

        int rd = gen(random);
        int rd2= gen2(random);

        std::cout << rd << " " << rd2 << std::endl;

        switch(rd){
        case 0:
            x = 90;
            y = 65;
            break;
        case 1:
            x = 720;
            y = 490;
            break;
        case 2:
            x = 90;
            y = 490;
            break;
        case 3:
            x = 720;
            y = 65;
            break;
        }

        Mob* mob = new Mob("boule",2,x,y,20,20,10,250);
        entityMap.insert(mob->getID(),mob);
        entityTypeMap.insert("boule",mob->getID());
        connect(((Mob*) entityMap.value(mob->getID())),SIGNAL(mobDeath(int)),this,SLOT(killMob(int)));

//        switch(rd2){
//        case 0: //UP
//            x = 400;
//            y = 0;
//            angle = 0;
//            break;
//        case 1: //DOWN
//            x = 400;
//            y = 600;
//            angle = PI;
//            break;
//        case 2: //LEFT
//            x = 0;
//            y = 300;
//            angle = -PI/2;
//            break;
//        case 3: //RIGHT
//            x = 800;
//            y = 300;
//            angle = PI/2;
//            break;
//        }
//        bool canPop = true;
//        if(rd2 < 4){
//            for(QMap<std::string,int>::iterator it = entityTypeMap.begin(); it != entityTypeMap.end(); it++ ){
//                if(it.key().compare("towerCanon") == 0
//                        && entityMap.value(it.value())->get_x() == x && entityMap.value(it.value())->get_y() == y){
//                    canPop = false;
//                }
//            }
//            if(canPop){
//                Mob* mob = new Mob("towerCanon",2,x,y,50,50,100,200,16*64);
//                mob->setAngle(angle);
//                mob->setBaseAngle(angle);
//                entityMap.insert(mob->getID(),mob);
//                entityTypeMap.insert("towerCanon",mob->getID());
//                connect(((Mob*) entityMap.value(mob->getID())),SIGNAL(mobDeath(int)),this,SLOT(killMob(int)));
//            }
//        }


        std::cout << popTimer.interval() << std::endl;
        popTimer.setInterval(popTimer.interval()-WAVETIMER);
    }
}

bool Environment::shootedMob(Entite* mob){
    for(int i = 0
        ;i < entityTypeMap.values("bullet").size()
        ;i++){

        if(mob->get_trigger().intersection(((Bullet*) entityMap.value(entityTypeMap.values("bullet")[i]))->get_trigger())
                && ((Bullet*) entityMap.value(entityTypeMap.values("bullet")[i]))->getParent().compare(mob->get_nom()) != 0){
            return true;
        }
    }
    for(int i = 0
        ;i < entityTypeMap.values("towerBullet").size()
        ;i++){

        if(mob->get_trigger().intersection(((Bullet*) entityMap.value(entityTypeMap.values("towerBullet")[i]))->get_trigger())
                && ((Bullet*) entityMap.value(entityTypeMap.values("towerBullet")[i]))->getParent().compare(mob->get_nom()) != 0){
            entityMap.remove(entityTypeMap.values("towerBullet")[i]);
            entityTypeMap.remove("towerBullet",entityTypeMap.values("towerBullet")[i]);
            return true;
        }
    }
    return false;
}

Player* Environment::getHero(){
    return (Player*) entityMap.value(heroID);
}



envTime convertTime(int millisec){
    envTime currentTime;
    currentTime.centSec = (millisec)%100;
    currentTime.second = (millisec/1000)%60;
    currentTime.minute = millisec/60000;

    return currentTime;

}

QString timeToString(envTime t){
    QString tmpS(QString::number(t.minute) + QString(":")
                 + QString::number(t.second) + QString(":")
                 + QString::number(t.centSec));

    return tmpS;

}
