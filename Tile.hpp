#ifndef TILE_HPP
#define TILE_HPP

#include "Point.hpp"
#include "Resource.hpp"
#include <map>

using namespace std;
class Player;

namespace game {
class Tile {
public:
  // CREATE TILE
  Tile(Resource resource, int id ,int number) : resource(resource),id(id) ,number(number) {}
  ~Tile() = default;
  //---------------------------------------------------------------------------------------

  // getters
  //  get the resource of the tile
  Resource getResource() const { return resource; }
  // get the number of the tile (Dice)
  int getNumber() const { return number; }
  // get the occupants of the tile
  const map<Player *, int> &getOccupants() const{ return occupants;};
  //---------------------------------------------------------------------------------------

  // adders
  // add settlement to the tile
  void addSettlement(Player *player) {
    occupants[player] = 1;
    addOccupant(player);
  }
  // add city to the tile
  void addCity(Player *player) {
    occupants[player] = 2;
    addOccupant(player);
  };
  // add road to the tile
  void addRoad(Player *player, Point *start, Point *end) {};
  // add occupant to the tile
  void addOccupant(Player *player);
  //---------------------------------------------------------------------------------------

private:
  int id;
  int number;
  Resource resource;
  map<Player *, int> occupants;
  int numberOfBuildings = 0;
};

} // namespace game

#endif