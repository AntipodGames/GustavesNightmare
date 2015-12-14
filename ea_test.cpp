#include "ea4age/population.h"
#include "ea4age/cell.h"
#include "ea4age/environment_descriptor.hpp"

int main(){
    ea4age::Population pop(1);
    ea4age::Cell cell = pop.get_cells().front();
    ea4age::Environment_Descriptor ED;

    ED.down_left.mobs_info = std::vector<ea4age::Mob_Info>(1);
    ED.down_left.mobs_info[0] = (ea4age::Mob_Info(3.14,20));
    ED.left_up.mobs_info = std::vector<ea4age::Mob_Info>(0);
    ED.right_down.mobs_info = std::vector<ea4age::Mob_Info>(0);
    ED.up_right.mobs_info = std::vector<ea4age::Mob_Info>(0);
    ea4age::Cell::actions actions;

    actions = cell.behaviour(ED);
    return 0;
}
