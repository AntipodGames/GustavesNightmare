#ifndef INGAME_H
#define INGAME_H
#include <QWidget>
#include <QtGui>


#include <QMessageBox>
#include <qsfcanvas.h>
#include <environment.h>
#include <ingameui.h>
#include "soundmanager.h"
#include "ai_player.h"
#include "ea4age/cell.h"
#include "ea4age/population.h"

class InGame : public QWidget
{
    Q_OBJECT
public:
    InGame( int width, int height);
    InGame();

    void init();
    void ai_init();
public slots :
//    void changeMusic(QString);


private:
    QVBoxLayout* container;
    QSFcanvas* SFMLView;
    Environment* env;
//    InGameUI* gui;
    QFrame* MainFrame;
//    SoundManager* SM;

    AI_Player* AI;
    ea4age::Population _population;

    int Width;
    int Height;

};

#endif // INGAME_H
