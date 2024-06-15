#ifndef MAP_HPP
#define MAP_HPP
#include "Dice.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "Road.hpp"
#include "Point.hpp"
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>
#pragma once

using namespace std;

namespace game {
class Point;
class Tile;
class Dice;
class Map {

public:
  // Create and destroy a map
  Map();
  ~Map() = default;

  //-------------------------------------------------------------------------

  // adders and getters
  // get player
  Player *getPlayer(size_t id) const { return players[id]; };
  // return all players
  std::vector<Player *> getPlayers() { return players; };
  // add player
  void addPlayer(Player *player) { players.push_back(player); };
  // add tile
  void addTile(Tile *tile) { tiles.push_back(tile); };
  // get tile
  Tile *getTile(size_t id) const {
    if (tiles.size() > id)
      return tiles[id];
    else
      throw std::out_of_range("Index out of range [getTile]");
  };
  // get tiles
  std::vector<Tile *> getTiles() {
    if (tiles.size() > 0)
      return tiles;
    else
      throw std::out_of_range("Index out of range [getTile]");
  };
  // add point
  void addPoint(Point *point) { points.push_back(point); };
  // get point
  Point *getPoint(size_t id) const {
    if (id < points.size()) {
      return points[id];
    } else {
      std::cout << "points.size() = " << points.size() << std::endl;
      std::cout << id << std::endl;
      return nullptr;
    }
  };
  // get points
  std::vector<Point *> getPoints() {
    if (points.size() > 0)
      return points;
    else {
      return {};
    }
  };
   // get roads from that point
  std::vector<Road> getRoadInMap() const {
    if (roadsInMap.size() > 0)
      return roadsInMap;
    else
      return {};
  }
  // add road to that point
  void addRoadInMap(Road road) { this->roadsInMap.push_back(road); }

  //-------------------------------------------------------------------------

  static Map &getInstance() {
    // If the instance doesn't exist, create it
    if (!instance) {
      instance = new Map();
    }
    return *instance;
  }

  Map(const Map &) = delete;
  Map &operator=(const Map &) = delete;

private:
  static const size_t NUM_PLAYERS = 3;
  static Map *instance;
  std::vector<Player *> players;
  std::vector<Tile *> tiles;
  std::vector<Point *> points;
  std::vector<Road> roadsInMap;
  Dice *dice;
};

} // namespace game

#endif
