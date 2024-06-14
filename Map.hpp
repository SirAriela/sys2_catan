#ifndef MAP_HPP
#define MAP_HPP
#pragma once

#include "Dice.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Tile.hpp"
#include <cstddef>
#include <vector>

using namespace std;

namespace game {
class Point;
class Tile;
class Dice;
class Map {

public:
  // Create and destroy a map
  Map();
  ~Map() {
    for (auto player : players) {
      delete player;
    }
    for (auto tile : tiles) {
      delete tile;
    }
    for (auto point : points) {
      delete point;
    }
    delete dice;
  }; // namespace game
  //-------------------------------------------------------------------------

  // adders and getters
  // get player
  Player *getPlayer(int id) const { return players[id]; };
  // add player
  void addPlayer(Player *player) { players.push_back(player); };
  // add tile
  void addTile(Tile *tile) { tiles.push_back(tile); };
  // get tile
  Tile *getTile(int id) const { return tiles[id]; };
  // add point
  void addPoint(Point *point) { points.push_back(point); };
  // get point
  Point *getPoint(int id) const { return points[id]; };

  //-------------------------------------------------------------------------

  static Map &getInstance() {
    // If the instance doesn't exist, create it
    if (!instance) {
      instance = new Map();
    }
    return *instance;
  }

  Map(const Map &) = delete;
  // Map &operator=(const Map &) = delete;

private:
  static const size_t NUM_PLAYERS = 3;
  static Map *instance;
  std::vector<Player *> players;
  std::vector<Tile *> tiles;
  std::vector<Point *> points;
  Dice *dice;
};

} // namespace game

#endif
