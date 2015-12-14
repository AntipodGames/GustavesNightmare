#include "ingame.h"

InGame::InGame()
{
}

InGame::InGame(int width, int height)
{
    MainFrame = new QFrame();
    MainFrame->resize(width, height-50);
    env = new Environment(width,height);
    SFMLView = new QSFcanvas(QPoint(0,0),QSize(width,height),MainFrame);
//    gui = new InGameUI(QPoint(0,height-50),QSize(width,50));

    AI = new AI_Player;

    Width = width;
    Height = height;

    setMinimumSize(width,height);


//    SM = new SoundManager("Fly_menu.mp3",12800);

    container = new QVBoxLayout(this);

    container->addWidget(MainFrame);
//    container->addWidget(gui);
    container->setMargin(0);





}

void InGame::init(){


    connect(env,SIGNAL(sendEM(QMap<int,Entite*>&)),SFMLView,SLOT(receiveEM(QMap<int,Entite*>&)));


    //GUI.......................................................................
    connect(env,SIGNAL(sendLife(int)),SFMLView,SLOT(updateVie(int)));
    connect(env,SIGNAL(sendTimer(int)),SFMLView,SLOT(updateTimer(int)));
    //..........................................................................

    env->init();


    connect(env,SIGNAL(display(std::string,int,int)),SFMLView,SLOT(dispEvent(std::string,int,int)));
    connect(env,SIGNAL(mobDeath(int,int)),SFMLView->getDM(),SLOT(applyStormBlink(int,int)));

    //gestion de la pause-----------------------------------------------------
    connect(SFMLView,SIGNAL(setPause()),env,SLOT(pause())); //pause
//    connect(Pause,SIGNAL(accepted()),env,SLOT(pause()));
//    connect(Pause,SIGNAL(accepted()),SFMLView,SLOT(pause()));
//    connect(gui->pause,SIGNAL(pressed()),env,SLOT(pause()));
//    connect(gui->pause,SIGNAL(pressed()),SFMLView,SLOT(pause()));
    //----------------------------------------------------------------------



    //Signaux et slots relatif au controle du joueur.............................................
    connect(SFMLView,SIGNAL(turnLeft()),env->getHero(),SLOT(left()));
    connect(SFMLView,SIGNAL(turnRight()),env->getHero(),SLOT(right()));
    connect(SFMLView,SIGNAL(turnUp()),env->getHero(),SLOT(up()));
    connect(SFMLView,SIGNAL(turnDown()),env->getHero(),SLOT(down()));
    connect(SFMLView,SIGNAL(sendMousePos(int,int)),env->getHero(),SLOT(updateAngle(int,int)));
    connect(SFMLView,SIGNAL(sigShoot(int)),env,SLOT(shoot(int)));
    connect(env,SIGNAL(sendMort()),SFMLView,SLOT(heroDeath()));
    connect(env,SIGNAL(sendMort()),AI,SLOT(death()));
    //...........................................................................................



  //  connect(env,SIGNAL(chgMusic(QString)),this,SLOT(changeMusic(QString)));


    SFMLView->initView(400,300,Width,Height);

    MainFrame->show();
    SFMLView->show();



//    SM->playPause();

}

void InGame::ai_init(){

    _population.init(1);

    AI->set_cell(_population.get_cells()[0]);
    AI->init();

    env->init();
    env->set_ai_mode(true);


    connect(AI,SIGNAL(go_down()),env->getHero(),SLOT(down()));
    connect(AI,SIGNAL(go_left()),env->getHero(),SLOT(left()));
    connect(AI,SIGNAL(go_right()),env->getHero(),SLOT(right()));
    connect(AI,SIGNAL(go_up()),env->getHero(),SLOT(up()));
    connect(AI,SIGNAL(shoot(int)),env,SLOT(shoot(int)));
    connect(AI,SIGNAL(go_to_angle(double)),env->getHero(),SLOT(updateAngle(double)));

    connect(env,SIGNAL(send_info_to_ai(QMap<int,Entite*>,QMultiMap<std::string,int>,Player)),
            AI,SLOT(compute_ed(QMap<int,Entite*>,QMultiMap<std::string,int>,Player)));

    connect(env,SIGNAL(sendEM(QMap<int,Entite*>&)),SFMLView,SLOT(receiveEM(QMap<int,Entite*>&)));
    connect(env,SIGNAL(sendMort()),SFMLView,SLOT(heroDeath()));


    //GUI.......................................................................
    connect(env,SIGNAL(sendLife(int)),SFMLView,SLOT(updateVie(int)));
    connect(env,SIGNAL(sendTimer(int)),SFMLView,SLOT(updateTimer(int)));
    //..........................................................................



    connect(env,SIGNAL(display(std::string,int,int)),SFMLView,SLOT(dispEvent(std::string,int,int)));
    connect(env,SIGNAL(mobDeath(int,int)),SFMLView->getDM(),SLOT(applyStormBlink(int,int)));


    SFMLView->initView(400,300,Width,Height);

    MainFrame->show();
    SFMLView->show();
}

//void InGame::changeMusic(QString str){
//    SM->playPause();

//    SM = new SoundManager(str,12800);
//    SM->playPause();

//}


