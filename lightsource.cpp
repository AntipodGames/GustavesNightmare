#include "lightsource.h"


bool lightSource::onLoad()
{

    // Load the shader
    if (!m_shader.loadFromFile("storm.vert", "blink.frag") || !shader.loadFromFile("storm.vert","blink.frag"))
        return false;

    return true;
}

void lightSource::onUpdate()
{
    float time;
    float radius;

    for(QMap<int,QPoint>::iterator it = pos.begin()
        ; it != pos.end();it++){
        time= timers.value(it.key()).elapsed();
        int freq = 20;
        radius = 100 + std::cos((time)/1000.*freq-PI)*100;

        if(radius >=180){
            radius = 0;
        }

        if(time < 2*PI/freq*1000){
            m_shader.setParameter("storm_position" + QString::number(it.key()).toStdString(), it.value().x(), it.value().y());
            m_shader.setParameter("storm_inner_radius"+ QString::number(it.key()).toStdString(), radius*3);
            m_shader.setParameter("storm_total_radius"+ QString::number(it.key()).toStdString(), radius/2);
        }else{
            if(currentLight > it.key())
                currentLight = it.key();

            timers.remove(it.key());
            pos.remove(it.key());
            nbrLight--;
        }
    }


}

void lightSource::launch(float x, float y){
    if(m_isLoaded){

        if(nbrLight < 10){
            QTime tmpTime;
            tmpTime.start();
            timers.insert(currentLight,tmpTime);

            pos.insert(currentLight,QPoint(x,y));
            currentLight++;
            nbrLight++;
        }
    }
}

void lightSource::onDraw(sf::RenderTarget& target, sf::RenderStates states) const
{

    states.shader = &m_shader;
    target.draw(vArray, states);

}
