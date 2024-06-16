#ifndef logic_HPP
#define logic_HPP

#include "Map.hpp"
#include "Player.hpp"
#include "Robber.hpp"
#include "Tile.hpp"

namespace game {

class Logic {
public:
  static void getResorces(Map &map, int rollResult) {
    for (auto point : map.getPoints()) {
      for (auto tile : point->getTiles()) {
        if(map.getRobber()->getTile() == tile) continue;
        if (tile->getNumber() == rollResult) {
          if (point->getBuilding() == BuildingType::Settlement) {
            point->getOwner()->addResource(tile->getResource(), 1);
          } else if (point->getBuilding() == BuildingType::City) {
            point->getOwner()->addResource(tile->getResource(), 2);
          }
        }
      }
    }
  }

  static void moveRobber(Player &player, Tile *tile) {
    Map *instance = Map::getInstance();
    Robber *robber = instance->getRobber();
  }
};

} // namespace game

#endif