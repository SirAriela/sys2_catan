#include "Tile.hpp"


namespace game {

void Tile::addOccupant(int player) {
  if (numberOfBuildings < 6) {
    numberOfBuildings++;
    occupants.push_back(player);

  } else {
    throw("Too many buildings on tile");
  }
}

} // namespace game