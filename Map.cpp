#include "Map.hpp"

namespace game
{
    //get the player with the id
    Player *Map::getPlayer(int id) const
    {
        return players[id];
    }
    //get the player with the id
    void Map::setPlayer(Player *player)
    {
        players[player->getId()] = player;
    }
    //get the player with the id
    void Map::setTile(Tile *tile)
    {
        tiles[tile->getId()] = tile;
    }
    //get the player with the id
    void Map::setPoint(Point *point)
    {
        points[point->getId()] = point;
    }
    //get the player with the id
    void Map::setDice(Dice *dice)
    {
        this->dice = dice;
    }
    //get the player with the id
    void Map::setPlayers(Player **players)
    {
        this->players = players;
    }
    //get the player with the id
    void Map::setTiles(Tile **tiles)
    {
        this->tiles = tiles;
    }
    //get the player with the id
    void Map::setPoints(Point **points)
    {
        this->points = points;
    }
} // namespace game