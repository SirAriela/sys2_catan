#ifndef POIINT_HPP
#define POIINT_HPP


#pragma once

#include "Building.hpp"
#include <vector>
#include "Road.hpp"
#include "Player.hpp"

namespace game {
class Tile;

class Point {

public:
  // tell us what tiles it is on, what building is on it, and what neighbors it has
  Point(std::vector<Tile> tiles, BuildingType building,
        std::vector<Point> neighbor)
      : tiles(tiles), building(building), neighbor(neighbor) {}
  ~Point() = default;

  //-------------------------------------------------------------------------
  // get Tile
  std::vector<Tile> getTile() const { return tiles; }


  // add Building
  void SetBuilding(BuildingType building) { this->building = building; }
  // get the building
  BuildingType getBuilding() const { return building; }
  //----------------------------------------------------------------------------


  // add neighbor
  void addNeighbor(Point neighbor) { this->neighbor.push_back(neighbor); }
  // get the neighbors
  std::vector<Point> getNeighbor() const { return neighbor; }
  //---------------------------------------------------------------------------

  // get roads from that point
  std::vector<Road> getRoadInMap() const { return roadsInMap; }
  // add road to that point
  void addRoadInMap(Road road) { this->roadsInMap.push_back(road); }
  //---------------------------------------------------------------------------

  // set owner
  void setOwner(Player *owner) { this->owner = owner; }
  // get owner
  Player *getOwner() const { return owner; }

private:
  std::vector<Tile> tiles;
  BuildingType building;
  Player *owner;
  std::vector<Point> neighbor;
  std::vector<Road> roadsInMap;
};

} 

#endif
