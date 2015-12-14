#ifndef ENTITE_H
#define ENTITE_H
#include <QTimer>
#include <QTime>
#include "animatedsprite.h"
#include "imagemanager.h"
#include "tzellipse.h"
#include "carte.h"
#include "cmath"
#include <QObject>

static const std::string stateStrings[] = {"Right","Left","Down","Up","Dead"};
static int statID = 0;
class Entite : public QObject
{

    Q_OBJECT

public:

   /* typedef struct typetourelle{
        forme form;
        int**  physx;
    }typetourelle;
    static QVector<int**> ttours;*/

    typedef enum state {
        RIGHT,
        LEFT,
        DOWN,
        UP,
        DEAD
    }state;

    //*Constructeurs
    Entite();
    Entite(const Entite&);
    Entite(std::string name, double v, int px, int py, int w, int h, int vi);
    //*/


    //*Methodes
    virtual void perdVie(int degats);

//    virtual void chFrame();4

    virtual void incrFrame(float f);


    static float calcAngle(float x1, float y1, float x2, float y2);

    virtual void switchAllowToShoot(bool b);
    virtual void restartInternalClock();

 //   virtual std::string toString()=0;
    //*/

    //*Getters
    virtual float get_x() const;
    virtual float get_y() const;

    virtual int get_vitesse();
    virtual std::string get_nom();

   // virtual AnimatedSprite& get_image();
    virtual TzEllipse& get_trigger();

    virtual int getID();

    virtual int getVie();
    virtual float getAngle();

    virtual int getFrame();

    virtual bool AllowToShoot();
    //*/

    //*Setters
    virtual void set_x(int);
    virtual void set_y(int);
    virtual void set_x(double);
    virtual void set_y(double);
    virtual void set_vitesse(int);
    virtual void set_nom(std::string);
    virtual void setState(state);
    virtual void setAngle(float);
    //*/


public slots:
    virtual void canShoot();


protected:
    //*Attributs
    float x;
    float y;
    int width;
    int height;
    float vitesse; // unit : pixel/ms
    std::string nom;
 //   AnimatedSprite image;
    TzEllipse tz;
    int vie;
    float angle;
    state currentState;
    float currentFrame;
    QTimer internalClock;
    QTime frameClock;
    bool allowToShoot = true;
    //*/

    //*Fonctions internes
    virtual bool addX(int);
    virtual bool addY(int);
    virtual bool addX(double);
    virtual bool addY(double);
    //*/

    int ID;


};



#endif // ENTITE_H
