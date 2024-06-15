#include "Tile.hpp"
#include <iostream>

namespace game {

void Tile::addOccupant(int player) {
  if (numberOfBuildings < 6) {
    cout << "herer" << endl;
    numberOfBuildings++;
    occupants.push_back(player);

  } else {
    throw("Too many buildings on tile");
  }
}

} // namespace game