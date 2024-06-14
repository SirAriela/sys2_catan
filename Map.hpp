#ifndef MAP_HPP
#define MAP_HPP

#include "Player.hpp"
#include "Dice.hpp"
#include <vector>
#include <cstddef>

using namespace std;

namespace game {
class Point;
class Tile;
class Dice;
class Map {
   
public:
    Player *getPlayer(int id) const;
    void setPlayer(Player *player);
    void setTile(Tile *tile);
    void setPoint(Point *point);
    void setPlayers(Player **players, size_t size);
    void setTiles(Tile **tiles, size_t size);
    void setPoints(Point **points, size_t size);

private:
    std::vector<Player *> players;
    std::vector<Tile *> tiles;
    std::vector<Point *> points;
    Dice *dice;
};

}

#endif
