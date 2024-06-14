#include "Map.hpp"

namespace game
{
    Tile tile1(Resource::Iron, 0, 10); 
    Tile tile2(Resource::Wool, 1, 2);
    Tile tile3(Resource::Wood, 2, 9);
    Tile tile4(Resource::Wheat, 3, 12);
    Tile tile5(Resource::Brick, 4, 6);
    Tile tile6(Resource::Wool, 5, 4);
    Tile tile7(Resource::Brick, 6, 10);
    Tile tile8(Resource::Wheat, 7, 9);
    Tile tile9(Resource::Wood, 8, 11);
    Tile tile10(Resource::None, 9, 0);
    Tile tile11(Resource::Wood, 10, 3);
    Tile tile12(Resource::Iron, 11, 8);
    Tile tile13(Resource::Wood, 12, 8);
    Tile tile14(Resource::Iron, 13, 3);
    Tile tile15(Resource::Wheat, 14, 4);
    Tile tile16(Resource::Wool, 15, 5);
    Tile tile17(Resource::Brick, 16, 5);
    Tile tile18(Resource::Wheat, 17, 6);
    Tile tile19(Resource::Wool, 18, 11);

    Point point1({tile1}, BuildingType::None, vector<Point>());
    Point point2({tile1}, BuildingType::None, vector<Point>());
    Point point3({tile1,tile2}, BuildingType::None, vector<Point>());
    Point point4({tile2}, BuildingType::None, vector<Point>());
    Point point5({tile2,tile3}, BuildingType::None, vector<Point>());
    Point point6({tile3}, BuildingType::None, vector<Point>());
    Point point7({tile3,tile4}, BuildingType::None, vector<Point>());

}