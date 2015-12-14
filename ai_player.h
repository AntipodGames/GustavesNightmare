#ifndef AI_PLAYER_H
#define AI_PLAYER_H
#include <QObject>
#include "ea4age/cell.h"
#include "ea4age/environment_descriptor.hpp"
#include "qmap.h"
#include "player.h"

class AI_Player : public QObject
{
    Q_OBJECT

public:

    AI_Player(){}

    AI_Player(const ea4age::Cell& cell) :
    _cell(cell){
        init();
    }


//    AI_Player(const AI_Player& ai_p) :
//        _cell(ai_p._cell),
//        _ed(ai_p._ed){
//        init();
//    }

    void init();


    void set_cell(const ea4age::Cell& cell){_cell = cell;}

public slots:
    void exec_action();
    void compute_ed(const QMap<int, Entite*>& entity_map,
                    const QMultiMap<std::string,int>& entity_type_map,
                    const Player& player );
    void death(){_alive = false;}

signals:
    void go_left();
    void go_right();
    void go_up();
    void go_down();
    void shoot(int);
    void go_to_angle(double);


private:

    void compute_action();

    ea4age::Cell _cell;
    ea4age::Environment_Descriptor _ed;
    QTimer _timer;
    bool _alive;

    struct Controlers{
        bool left;
        bool right;
        bool up;
        bool down;
        bool shoot;
        double angle;
    };

    Controlers _controlers;
};

#endif // AI_PLAYER_H
