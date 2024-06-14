#include "Tile.hpp"

namespace game {


const map<Player *, int> &Tile::getOccupants() const {
    return occupants;
};

void Tile::addOccupant(Player *player) {
    if(numberOfBuildings < 6){
        numberOfBuildings++;
        occupants[player] = 1;
    }
    else{
        __throw_runtime_error ("Too many buildings on tile");
    }
   

};

}