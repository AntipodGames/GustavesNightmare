#include "ai_player.h"

void AI_Player::init(){



    //init controlers
    _controlers.down = false;
    _controlers.left = false;
    _controlers.right = false;
    _controlers.up = false;
    _controlers.shoot = false;
    _controlers.angle = 0;

    connect(&_timer,SIGNAL(timeout()),this,SLOT(exec_action()));
    _timer.start(_cell.get_genome()[1]);

    _alive = true;
}

void AI_Player::compute_ed(const QMap<int, Entite *> &entity_map,
                           const QMultiMap<std::string, int> &entity_type_map,
                           const Player &player){

    _ed.down_left.mobs_info.clear();
    _ed.right_down.mobs_info.clear();
    _ed.left_up.mobs_info.clear();
    _ed.up_right.mobs_info.clear();

    for(QMultiMap<std::string, int>::const_iterator it_type = entity_type_map.begin();
        it_type != entity_type_map.end(); it_type++){

        if(it_type.key().compare("boule") == 0 || it_type.key().compare("towerCanon") == 0){

            float x = entity_map.value(it_type.value())->get_x(),
                  y = entity_map.value(it_type.value())->get_y();

            double angle = Entite::calcAngle(player.get_x(), player.get_y(),x,y);
            double distance = std::sqrt((player.get_x() - x)*(player.get_x() - x) + (player.get_y() - y)*(player.get_y() - y));

            if(angle > -PI/2. && angle <= 0 )//UP RIGHT
                _ed.up_right.mobs_info.push_back(ea4age::Mob_Info(angle,distance));
            else if(angle < 6.*PI/4. && angle >= PI)//UP LEFT
                _ed.left_up.mobs_info.push_back(ea4age::Mob_Info(angle,distance));
            else if(angle < PI && angle >= PI/2. ) //DOWN LEFT
                _ed.down_left.mobs_info.push_back(ea4age::Mob_Info(angle,distance));
            else if(angle < PI/2 && angle > 0)// DOWN RIGHT
                _ed.right_down.mobs_info.push_back(ea4age::Mob_Info(angle,distance));
        }
    }


}

void AI_Player::compute_action(){
    ea4age::Cell::actions action = _cell.behaviour(_ed);

    std::cout << "r d " << _ed.right_down.mobs_info.size()
              << " u r " << _ed.up_right.mobs_info.size()
              << " d l " << _ed.down_left.mobs_info.size()
              << " l u "  << _ed.left_up.mobs_info.size()
              << std::endl;

    _controlers.left = action.left;
    _controlers.right = action.right;
    _controlers.down = action.down;
    _controlers.up = action.up;
    _controlers.shoot = action.shoot;
    _controlers.angle = action.angle;
}

void AI_Player::exec_action(){

    if(!_alive){

        _cell.eval(/**/);

        _timer.stop();
        return;
    }
    compute_action();

std::cout << "exec action  :"
          << " d " << _controlers.down
          << " l " << _controlers.left
          << " r " << _controlers.right
          << " u " << _controlers.up
          << " s " << _controlers.shoot
          << " a " << _controlers.angle
          << std::endl;


    emit go_to_angle(_controlers.angle);

    if(_controlers.left)
        emit go_left();
    if(_controlers.right)
        emit go_right();
    if(_controlers.up)
        emit go_up();
    if(_controlers.down)
        emit go_down();
    if(_controlers.shoot)
        emit shoot(1);

}
