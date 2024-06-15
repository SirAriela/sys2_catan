#ifndef POIINT_HPP
#define POIINT_HPP

#include <stdexcept>
#pragma once

#include "Building.hpp"
#include "Tile.hpp" 
#include <vector>

namespace game {

class Tile;
class Player;
class Point {

public:
  // tell us what tiles it is on, what building is on it, and what neighbors it
  // has
  Point(BuildingType building)
      : building(building),tiles({}), neighbor({}),
        owner(nullptr) {}
  ~Point() = default;

  //-------------------------------------------------------------------------
  // get Tile
  std::vector<Tile *> getTile() const {
    if (tiles.size() > 0)
      return tiles;
    else
      throw std::out_of_range("No tiles on this point");
  }

  // add Tile
  void addTile(Tile *tile) { this->tiles.push_back(tile); }
  // add tiles
  void addTiles(std::vector<Tile *> tiles) { 
  for(auto t : tiles)
    this->tiles.push_back(t);
   };

  // add Building
  void SetBuilding(BuildingType building) { this->building = building; }
  // get the building
  BuildingType getBuilding() const {
    if (building != BuildingType::None)
      return building;
    else {
      return BuildingType::None;
    }
  }
  //----------------------------------------------------------------------------

  // add neighbor
  void addNeighbor(Point neighbor) { this->neighbor.push_back(neighbor); }
  // get the neighbors
  std::vector<Point> getNeighbor() const {
    if (neighbor.size() > 0)
      return neighbor;
    else
      return {};
  }
  //---------------------------------------------------------------------------


  //---------------------------------------------------------------------------

  // set owner
  void setOwner(Player *owner) { this->owner = owner; }
  // get owner
  Player *getOwner() const {
    if (owner != nullptr)
      return owner;
    else
      return nullptr;
  }

private:
  std::vector<Tile *> tiles;
  BuildingType building;
  Player *owner;
  std::vector<Point> neighbor;
  
};

} // namespace game

#endif
