#ifndef ROBBER_HPP
#define ROBBER_HPP

#include "Tile.hpp"

namespace game {

class Robber {

public:
  Robber(Tile *tile) : tile(tile) {}
  ~Robber() = default;
  Tile *getTile() const { return tile; }

  void setTile(Tile *tile) { this->tile = tile; }

  Robber(const Robber &) = delete;
  Robber &operator=(const Robber &) = delete;

private:
  Tile *tile;
};

} // namespace game

#endif