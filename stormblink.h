#ifndef STORMBLINK_H
#define STORMBLINK_H
#include <cmath>

#include "gleffect.hpp"

class StormBlink : public GlEffect
{
public :

    StormBlink() :
    GlEffect("storm + blink")
    {
    }

    void launch();

private:
    bool onLoad();

    void onUpdate();

    void onDraw(sf::RenderTarget& target, sf::RenderStates states) const;


    sf::Shader m_shader;
};


#endif // STORMBLINK_H
