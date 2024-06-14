#ifndef POIINT_HPP
#define POIINT_HPP

#pragma once

#include "Building.hpp"
#include <vector>

namespace game{
    class Tile;

    class Point{
   
        public:
            //tell us what tiles it is on, what building is on it, and what neighbors it has
            std::vector<Tile> tile;
            BuildingType building;
            std::vector<Point> neighbor;
            std::vector<Point> roadsPossible;

            //create a point
            Point(std::vector<Tile> tile, BuildingType building,std::vector<Point> neighbor) : tile(tile), building(building), neighbor(neighbor) {}
            //getters and setters
            std::vector<Tile> getTile() const { return tile; }
            //get the building
            BuildingType getBuilding() const { return building; }
            // get the neighbors
            std::vector<Point> getNeighbor() const { return neighbor; }
            //set the building
            void setBuilding(BuildingType building) { this->building = building; }
            //get the roads that are possible
            std::vector<Point> getroadsPossible() const { return roadsPossible; }
};

}


#endif
