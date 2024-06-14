#ifndef TILE_HPP
#define TILE_HPP

#include "Recources.hpp"
#include <map>



using namespace std;
class Player;

namespace game {
class Tile {
public:
//create a tile with a resource and a number
    Tile(Resource resource, int number) : resource(resource), number(number) {}
    //get the resource of the tile
    Resource getResource() const { return resource; }
    //get the number on the tile (Dice)
    int getNumber() const { return number; }
    //get the id of the tile
    int getId() const { return id; }
    
    //tell us who is on the tile 
    const map<Player *, int> &getOccupants() const;
    //add an occupant to the tile
    void addOccupant(Player *player);

private:
    int id;
    int number;
    Resource resource;
    map<Player *, int> occupants;
    int numberOfBuildings; // should be 6 or less
};

} 

#endif // TILE_HPP