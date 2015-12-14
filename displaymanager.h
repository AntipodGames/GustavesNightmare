#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include <QVector>
#include <qsfml.h>
#include <SFML/System/Clock.hpp>
#include "animatedmanager.h"
#include "mob.h"
#include <QMap>
#include <utility>
#include "stormblink.h"
#include "lightsource.h"

class DisplayManager : public QObject
{

    Q_OBJECT

private:
    typedef std::pair<QPoint/*entityPos*/,int/*entityID*/> sprite;
    typedef QMap<int,QVector<sprite> > spriteMap;
    spriteMap sprites;
    QMap<int,Entite*> EM;
    QVector<std::string> listAnim;
    QVector<QPoint> listCoordAnim;
    QVector<float> listFrames;
    QVector<QPoint> lightEffects;
    Carte carte;
    sf::Clock clock;
    sf::VertexArray lightManager;

    StormBlink sb;
    lightSource ls;

    bool allowStormblink = false;

public slots:
    void applyStormBlink(int,int);

public:
    DisplayManager();    
    DisplayManager(const DisplayManager & dm) :
        sprites(dm.sprites),
        EM(dm.EM),
        listAnim(dm.listAnim),
        listCoordAnim(dm.listCoordAnim),
        listFrames(dm.listFrames),
        carte(dm.carte)
    {}
    void init(sf::RenderWindow&,TextureManager&);


    void add(int x, int y, int ID);
    void remove(int ID, int y);
    void setEM(QMap<int,Entite*>&);

    void addAnim(std::string, int x, int y);

    void display(AnimatedManager &, sf::RenderWindow &);



};

#endif // DISPLAYMANAGER_H
