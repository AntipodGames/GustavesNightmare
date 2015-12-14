#include "stormblink.h"

void StormBlink::launch(){
    if (m_isLoaded)
        timer.start();

}

bool StormBlink::onLoad()
{


    // Load the shader
    if (!m_shader.loadFromFile("wave.vert","neutre.frag"))
        return false;
    m_shader.setParameter("texture",sf::Shader::CurrentTexture);


    return true;
}

void StormBlink::onUpdate()
{

    if(timer.elapsed() < 500){
        float radius = 4;
        m_shader.setParameter("wave_phase", timer.elapsed());
        m_shader.setParameter("wave_radius", radius);
    }

}

void StormBlink::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.shader = &m_shader;
    target.draw(sprite, states);
}
