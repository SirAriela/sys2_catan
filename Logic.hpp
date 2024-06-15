#ifndef logic_HPP
#define logic_HPP

#include "Map.hpp"
#include "Player.hpp"

namespace game {

class Logic {
public:
  static void getResorces(Map &map, int rollResult) {
    for (auto point : map.getPoints()) {
      for (auto tile : point->getTiles()) {
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

  
};


} 

#endif