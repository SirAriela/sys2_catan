#ifndef ROAD_HPP
#define ROAD_HPP

#include "Player.hpp"

namespace game {
class Point;
class Road {

public:
  // create a road
  Road(Point *point1, Point *point2, Player *player)
      : point1(point1), point2(point2), owner(player) {}
  ~Road() = default;
  // get the points the road is on
  Point *getPoint1() const { return point1; }
  Point *getPoint2() const { return point2; }
  Player *getOwner() const { return owner; }

private:
  Point *point1;
  Point *point2;
  Player *owner;
};
} // namespace game

#endif