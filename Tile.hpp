#ifndef TILE_HPP
#define TILE_HPP

#include "Resource.hpp"

#include <vector>

using namespace std;
class Player;
class Point;

namespace game {
class Tile {
public:
  // CREATE TILE
  Tile(Resource resource, int id ,int number) : resource(resource),id(id) ,number(number),numberOfBuildings(0) ,occupants({}){}
  //---------------------------------------------------------------------------------------

  // getters
  //  get the resource of the tile
  Resource getResource() const { return resource; }
  
  // get the number of the tile (Dice)
  int getNumber() const { return number; }
  // get the occupants of the tile
  const vector<int> &getOccupants() const{ return occupants;};
  //---------------------------------------------------------------------------------------

  // adders
  // add occupant to the tile
  void addOccupant(int player);
  //---------------------------------------------------------------------------------------

private:
  int id;
  int number;
  Resource resource;
  vector<int> occupants;
  int numberOfBuildings;
};

} // namespace game

#endif