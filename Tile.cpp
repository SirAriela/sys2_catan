#include "Tile.hpp"

namespace game {
void Tile::addSettlement(Player *player) {
    occupants[player] = 1;
    
};

void Tile::addCity(Player *player) {
    occupants[player] = 2;
};

const map<Player *, int> &Tile::getOccupants() const {
    return occupants;
};

void Tile::addOccupant(Player *player) {
    if(numberOfBuildings < 6){
        numberOfBuildings++;
        occupants[player] = 1;
    }
    else{
        throw "Too many buildings on tile";
    }
   

};

}