#ifndef TILE_HPP
#define TILE_HPP

#include "Recources.hpp"
#include "DevelopmentCard.hpp"
#include <map>



using namespace std;
class Player;

namespace game {
class Tile {
public:
    Tile(Resource resource, int number) : resource(resource), number(number) {}
    Resource getResource() const { return resource; }
    int getNumber() const { return number; }
    void addSettlement(Player *player);
    void addCity(Player *player);
    const map<Player *, int> &getOccupants() const;

    // Add the declaration of getOccupants() here

private:
    int id;
    int number;
    Resource resource; // Declare the 'resource' member variable here
};

} // namespace game

#endif // TILE_HPP