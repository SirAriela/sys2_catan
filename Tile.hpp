#ifndef TILE_HPP
#define TILE_HPP

#include "Recources.hpp"
#include "DevelopmentCard.hpp"
#include "Point.hpp"
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
    //add settlement to the tile
    void addSettlement(Player *player);
    //add city to the tile
    void addCity(Player *player);
    //tell us who is on the tile (Dice tells who get the resources)
    const map<Player *, int> &getOccupants() const;

private:
    int id;
    int number;
    Resource resource;
    Point *points[6];
};

} 

#endif // TILE_HPP