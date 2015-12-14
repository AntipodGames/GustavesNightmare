#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include "qpoint.h"
#include <qmap.h>
#include "gleffect.hpp"
#include "cmath"

class lightSource : public GlEffect
{
public :

    lightSource() :
    GlEffect("light Source")
    {
    }


void launch(float x, float y);

private:
    bool onLoad();

    void onUpdate();



    void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;
    int nbrLight = 0;
    int currentLight = 0;
    QMap<int,QPoint> pos;
    QMap<int,QTime> timers;
    sf::Shader m_shader;
    sf::Shader shader;
};

#endif // LIGHTSOURCE_H
