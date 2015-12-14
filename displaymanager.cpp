#include "displaymanager.h"

DisplayManager::DisplayManager(){}

void DisplayManager::init( sf::RenderWindow &App,TextureManager& TM){

    //    float W = App.getSize().x;
    //    float H = App.getSize().y;
    //    float t = 0;
    //    float x = 0;
    //     float y = 0;

    //    for(float i = 0; i < App.getSize().x;i+=1){

    //        for(float j = 0; j < App.getSize().y;j+=1){

    //            t = 200.*exp(-(j-H/2.)/100.*(j-H/2.)/100.-(i-W/2.)/150.*(i-W/2.)/150.);
    //            int alpha_Rate = ((i-App.getSize().x/2)*(i-App.getSize().x/2))/(App.getSize().x*App.getSize().x/(127*4))
    //                                    +((j-App.getSize().y/2)*(j-App.getSize().y/2))/(App.getSize().y*App.getSize().y/(127*4));
    //            lightManager.append(sf::Vertex(sf::Vector2f(i,j),sf::Color(0,0,0,alpha_Rate)));
    //            j+=(int)t;

    //        }
    //        i+=(int)t;
    //    }



    //Initialisation du lightmanager
    for(int i = 0; i < App.getSize().x; i++){
        for(int j = 0; j < App.getSize().y; j++){
            int alpha_Rate =25+ ((i-App.getSize().x/2)*(i-App.getSize().x/2))/(App.getSize().x*App.getSize().x/(127*4))
                    +((j-App.getSize().y/2)*(j-App.getSize().y/2))/(App.getSize().y*App.getSize().y/(127*4));
            if(alpha_Rate > 255)
                alpha_Rate =255;
            lightManager.append(sf::Vertex(sf::Vector2f(i,j),sf::Color(0,0,0,alpha_Rate)));
        }
    }
    carte = Carte(TM,"graphisme/map3f.png","graphisme/map3f.png","graphisme/collisionmap.png");
    sb.load(carte.get_image("inf"));
    ls.load(sf::Sprite(),lightManager);
}


void DisplayManager::add(int x, int y, int ID){
    QPoint coord(x,y);
    sprite newSprite;
    newSprite.first = coord;
    newSprite.second = ID;
    if(sprites.contains(y/TAILLE)){ //si il y a deja des sprites
        QVector<sprite> tmp(sprites.value(y/TAILLE));
        tmp.append(newSprite);
        sprites.insert(y/TAILLE,tmp);
    }
    else{
        QVector<sprite> tmp;
        tmp.append(newSprite);
        sprites.insert(y/TAILLE,tmp);
    }
}

void DisplayManager::remove(int ID,int y){
    QVector<sprite> tmp(sprites.value(y/TAILLE));

    for(int i = 0; i < tmp.size(); i++){
        int tmpId = tmp[i].second;
        if(tmpId == ID){
            tmp.remove(i);
            tmp.squeeze();
            if(tmp.isEmpty())
                sprites.remove(y/TAILLE);
            else
                sprites.insert(y/TAILLE,tmp);
            return;
        }
    }
}

void DisplayManager::setEM(QMap<int, Entite *> & em){
    EM = em;
}

void DisplayManager::addAnim(std::string str,int x,int y){
    listAnim.append(str);
    listCoordAnim.append(QPoint(x,y));
    listFrames.append(1);
}

void DisplayManager::display(AnimatedManager &AM, sf::RenderWindow &App){


    //    carte.afficher(App,"inf");



    sb.update();


    App.draw(sb);

    for(int i = 0; i < listAnim.size();i++){

        AM.get(listAnim[i]).setFrame(listFrames[i]);
        AM.get(listAnim[i]).setPosition(listCoordAnim[i].x(),listCoordAnim[i].y());
        AM.get(listAnim[i]).affichage(App);
        listFrames[i] = listFrames[i] + 0.3;

        if(listFrames[i] > AM.get(listAnim[i]).getNbrFrame()){
            listAnim.remove(i);
            listAnim.squeeze();
            listCoordAnim.remove(i);
            listCoordAnim.squeeze();
            listFrames.remove(i);
            listFrames.squeeze();
            i--;
        }

    }

    for(QMap<int,Entite*>::iterator it = EM.begin(); it != EM.end(); it++  ){

        //        it.value()->get_trigger().draw(App);
        //AM.get(EM.value(tmp[i].second)->get_nom()).setFrame(EM.value(tmp[i].second)->getFrame());



        //Displays of all entity
        if(it.value()->get_nom().compare("towerCanon") == 0|| it.value()->get_nom().compare("towerCanonInFire") == 0){
            AM.get("towerBase").setPosition(it.value()->get_x(),it.value()->get_y());
            AM.get("towerBase").setAngle(((Mob*) it.value())->getBaseAngle());
            AM.get("towerBase").affichage(App);
            AM.get(it.value()->get_nom()).setAngle(it.value()->getAngle()-PI/2);
            AM.get(it.value()->get_nom()).setPosition(it.value()->get_x(),it.value()->get_y());
            AM.get(it.value()->get_nom()).setFrame(it.value()->getFrame());
            AM.get(it.value()->get_nom()).affichage(App);
        }else {
            AM.get(it.value()->get_nom()).setAngle(it.value()->getAngle());
            AM.get(it.value()->get_nom()).setFrame(it.value()->getFrame());
            AM.get(it.value()->get_nom()).setPosition(it.value()->get_x(),it.value()->get_y());
            AM.get(it.value()->get_nom()).affichage(App);

        }
    }


    ls.update();
    App.draw(ls);

}

void DisplayManager::applyStormBlink(int x, int y){

    ls.launch(x,y);
    sb.launch();

}
