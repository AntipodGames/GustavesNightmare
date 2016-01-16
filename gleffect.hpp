#ifndef GLEFFECT_H
#define GLEFFECT_H
#include "SFML/Graphics.hpp"
#include "animatedsprite.h"
#include <assert.h>
#include <QTime>

class GlEffect : public sf::Drawable
{
public:

    virtual ~GlEffect()
    {
    }


    void load(sf::Sprite s = sf::Sprite(),sf::VertexArray va = sf::VertexArray())
    {
        sprite = s;
        vArray = va;
        m_isLoaded = sf::Shader::isAvailable() && onLoad();
    }




    bool update()
    {
        if (m_isLoaded)
             onUpdate();
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (m_isLoaded)
        {
            onDraw(target, states);
        }

    }
protected :

    GlEffect(const std::string& name) :
        m_name(name),
        m_isLoaded(false)
    {
    }

    int posx,posy;
    QTime timer;
    sf::Sprite sprite;
    sf::VertexArray vArray;

private :

    // Virtual functions to be implemented in derived effects

    virtual bool onLoad() = 0;
    virtual void onUpdate() = 0;
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

protected :

    std::string m_name;
    bool m_isLoaded;

};

#endif // GLEFFECT_H
