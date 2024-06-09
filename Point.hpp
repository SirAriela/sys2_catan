#ifndef POIINT_HPP
#define POIINT_HPP


#include "Building.hpp"
#include "Tile.hpp"

namespace game{
    class Point{
        public:
            Tile **tile;
            Building building;
            Point** neighbor;
            Point(Tile **tile, Building building,Point** neighbor) : tile(tile), building(building), neighbor(neighbor) {}
            Tile **getTile() const { return tile; }
            Building getBuilding() const { return building; }
            Point** getNeighbor(int index) const { return neighbor; }
    };

}


#endif
