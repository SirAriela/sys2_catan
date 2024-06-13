#ifndef POIINT_HPP
#define POIINT_HPP

#pragma once

#include "Building.hpp"

namespace game{
    class Tile;

    class Point{
   
        public:
            //tell us what tiles it is on, what building is on it, and what neighbors it has
            Tile **tile;
            Building building;
            Point** neighbor;
            

            //create a point
            Point(Tile **tile, Building building,Point** neighbor) : tile(tile), building(building), neighbor(neighbor) {}
            //getters and setters
            Tile **getTile() const { return tile; }
            //get the building
            Building getBuilding() const { return building; }
            // get the neighbors
            Point** getNeighbor() const { return neighbor; }
};

}


#endif
