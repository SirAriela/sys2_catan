#include "Map.hpp"
#include "Tile.hpp"

namespace game {
Map *Map::instance = nullptr;

Map::Map() {
  // Crate Tiles for map
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

  addTile(&tile1);
  addTile(&tile2);
  addTile(&tile3);
  addTile(&tile4);
  addTile(&tile5);
  addTile(&tile6);
  addTile(&tile7);
  addTile(&tile8);
  addTile(&tile9);
  addTile(&tile10);
  addTile(&tile11);
  addTile(&tile12);
  addTile(&tile13);
  addTile(&tile14);
  addTile(&tile15);
  addTile(&tile16);
  addTile(&tile17);
  addTile(&tile18);
  addTile(&tile19);

  // create Points for map
  Point point1({tile1}, BuildingType::None, vector<Point>());
  Point point2({tile1}, BuildingType::None, vector<Point>());
  Point point3({tile1, tile2}, BuildingType::None, vector<Point>());
  Point point4({tile2}, BuildingType::None, vector<Point>());
  Point point5({tile2, tile3}, BuildingType::None, vector<Point>());
  Point point6({tile3}, BuildingType::None, vector<Point>());
  Point point7({tile3}, BuildingType::None, vector<Point>());
  Point point8({tile4}, BuildingType::None, vector<Point>());
  Point point9({tile1, tile4}, BuildingType::None, vector<Point>());
  Point point10({tile1, tile4, tile5}, BuildingType::None, vector<Point>());
  Point point11({tile1, tile2, tile5}, BuildingType::None, vector<Point>());
  Point point12({tile2, tile5, tile6}, BuildingType::None, vector<Point>());
  Point point13({tile2, tile3, tile6}, BuildingType::None, vector<Point>());
  Point point14({tile3, tile6, tile7}, BuildingType::None, vector<Point>());
  Point point15({tile3, tile7}, BuildingType::None, vector<Point>());
  Point point16({tile7}, BuildingType::None, vector<Point>());
  Point point17({tile8}, BuildingType::None, vector<Point>());
  Point point18({tile4, tile8}, BuildingType::None, vector<Point>());
  Point point19({tile4, tile8, tile9}, BuildingType::None, vector<Point>());
  Point point20({tile4, tile5, tile9}, BuildingType::None, vector<Point>());
  Point point21({tile5, tile9, tile10}, BuildingType::None, vector<Point>());
  Point point22({tile5, tile6, tile10}, BuildingType::None, vector<Point>());
  Point point23({tile6, tile10, tile11}, BuildingType::None, vector<Point>());
  Point point24({tile6, tile7, tile11}, BuildingType::None, vector<Point>());
  Point point25({tile7, tile11, tile12}, BuildingType::None, vector<Point>());
  Point point26({tile7, tile12}, BuildingType::None, vector<Point>());
  Point point27({tile12}, BuildingType::None, vector<Point>());
  Point point28({tile8}, BuildingType::None, vector<Point>());
  Point point29({tile8, tile13}, BuildingType::None, vector<Point>());
  Point point30({tile8, tile9, tile13}, BuildingType::None, vector<Point>());
  Point point31({tile9, tile13, tile14}, BuildingType::None, vector<Point>());
  Point point32({tile9, tile10, tile14}, BuildingType::None, vector<Point>());
  Point point33({tile10, tile14, tile15}, BuildingType::None, vector<Point>());
  Point point34({tile10, tile11, tile15}, BuildingType::None, vector<Point>());
  Point point35({tile11, tile15, tile16}, BuildingType::None, vector<Point>());
  Point point36({tile11, tile12, tile16}, BuildingType::None, vector<Point>());
  Point point37({tile12, tile16}, BuildingType::None, vector<Point>());
  Point point38({tile12}, BuildingType::None, vector<Point>());
  Point point39({tile13}, BuildingType::None, vector<Point>());
  Point point40({tile13, tile17}, BuildingType::None, vector<Point>());
  Point point41({tile13, tile14, tile17}, BuildingType::None, vector<Point>());
  Point point42({tile14, tile17, tile18}, BuildingType::None, vector<Point>());
  Point point43({tile14, tile15, tile18}, BuildingType::None, vector<Point>());
  Point point44({tile15, tile18, tile19}, BuildingType::None, vector<Point>());
  Point point45({tile15, tile16, tile19}, BuildingType::None, vector<Point>());
  Point point46({tile16, tile19}, BuildingType::None, vector<Point>());
  Point point47({tile16}, BuildingType::None, vector<Point>());
  Point point48({tile17}, BuildingType::None, vector<Point>());
  Point point49({tile17}, BuildingType::None, vector<Point>());
  Point point50({tile17, tile18}, BuildingType::None, vector<Point>());
  Point point51({tile18}, BuildingType::None, vector<Point>());
  Point point52({tile18, tile19}, BuildingType::None, vector<Point>());
  Point point53({tile19}, BuildingType::None, vector<Point>());
  Point point54({tile19}, BuildingType::None, vector<Point>());

//build the neighbors
  point1.addNeighbor(point2);
  point1.addNeighbor(point9);
  point2.addNeighbor(point1);
  point2.addNeighbor(point3);
  point3.addNeighbor(point2);
  point3.addNeighbor(point4);
  point3.addNeighbor(point11);
  point4.addNeighbor(point3);
  point4.addNeighbor(point5);
  point5.addNeighbor(point4);
  point5.addNeighbor(point6);
  point5.addNeighbor(point13);
  point6.addNeighbor(point5);
  point6.addNeighbor(point7);
  point7.addNeighbor(point6);
  point7.addNeighbor(point15);
  point8.addNeighbor(point9);
  point8.addNeighbor(point18);
  point9.addNeighbor(point1);
  point9.addNeighbor(point8);
  point9.addNeighbor(point10);
  point10.addNeighbor(point9);
  point10.addNeighbor(point11);
  point10.addNeighbor(point20);
  point11.addNeighbor(point3);
  point11.addNeighbor(point10);
  point11.addNeighbor(point12);
  point12.addNeighbor(point11);
  point12.addNeighbor(point13);
  point12.addNeighbor(point22);
  point13.addNeighbor(point5);
  point13.addNeighbor(point12);
  point13.addNeighbor(point14);
  point14.addNeighbor(point13);
  point14.addNeighbor(point15);
  point14.addNeighbor(point24);
  point15.addNeighbor(point7);
  point15.addNeighbor(point14);
  point15.addNeighbor(point16);
  point16.addNeighbor(point15);
  point16.addNeighbor(point26);
  point17.addNeighbor(point18);
  point17.addNeighbor(point28);
  point18.addNeighbor(point8);
  point18.addNeighbor(point17);
  point18.addNeighbor(point19);
  point19.addNeighbor(point18);
  point19.addNeighbor(point20);
  point19.addNeighbor(point30);
  point20.addNeighbor(point10);
  point20.addNeighbor(point19);
  point20.addNeighbor(point21);
  point21.addNeighbor(point20);
  point21.addNeighbor(point22);
  point21.addNeighbor(point32);
  point22.addNeighbor(point12);
  point22.addNeighbor(point21);
  point22.addNeighbor(point23);
  point23.addNeighbor(point22);
  point23.addNeighbor(point24);
  point23.addNeighbor(point34);
  point24.addNeighbor(point14);
  point24.addNeighbor(point23);
  point24.addNeighbor(point25);
  point25.addNeighbor(point24);
  point25.addNeighbor(point26);
  point25.addNeighbor(point36);
  point26.addNeighbor(point16);
  point26.addNeighbor(point25);
  point26.addNeighbor(point27);
  point27.addNeighbor(point26);
  point27.addNeighbor(point38);
  point28.addNeighbor(point17);
  point28.addNeighbor(point29);
  point29.addNeighbor(point28);
  point29.addNeighbor(point30);
  point29.addNeighbor(point39);
  point30.addNeighbor(point19);
  point30.addNeighbor(point29);
  point30.addNeighbor(point31);
  point31.addNeighbor(point30);
  point31.addNeighbor(point32);
  point31.addNeighbor(point41);
  point32.addNeighbor(point21);
  point32.addNeighbor(point31);
  point32.addNeighbor(point33);
  point33.addNeighbor(point32);
  point33.addNeighbor(point34);
  point33.addNeighbor(point43);
  point34.addNeighbor(point23);
  point34.addNeighbor(point33);
  point34.addNeighbor(point35);
  point35.addNeighbor(point34);
  point35.addNeighbor(point36);
  point35.addNeighbor(point45);
  point36.addNeighbor(point25);
  point36.addNeighbor(point35);
  point36.addNeighbor(point37);
  point37.addNeighbor(point36);
  point37.addNeighbor(point38);
  point37.addNeighbor(point47);
  point38.addNeighbor(point27);
  point38.addNeighbor(point37);
  point39.addNeighbor(point29);
  point39.addNeighbor(point40);
  point40.addNeighbor(point39);
  point40.addNeighbor(point41);
  point40.addNeighbor(point48);
  point41.addNeighbor(point31);
  point41.addNeighbor(point40);
  point41.addNeighbor(point42);
  point42.addNeighbor(point41);
  point42.addNeighbor(point43);
  point42.addNeighbor(point50);
  point43.addNeighbor(point33);
  point43.addNeighbor(point42);
  point43.addNeighbor(point44);
  point44.addNeighbor(point43);
  point44.addNeighbor(point45);
  point44.addNeighbor(point52);
  point45.addNeighbor(point35);
  point45.addNeighbor(point44);
  point45.addNeighbor(point46);
  point46.addNeighbor(point45);
  point46.addNeighbor(point47);
  point46.addNeighbor(point54);
  point47.addNeighbor(point37);
  point47.addNeighbor(point46);
  point48.addNeighbor(point40);
  point48.addNeighbor(point49);
  point49.addNeighbor(point48);
  point49.addNeighbor(point50);
  point50.addNeighbor(point49);
  point50.addNeighbor(point51);
  point51.addNeighbor(point50);
  point51.addNeighbor(point52);
  point52.addNeighbor(point51);
  point52.addNeighbor(point53);
  point53.addNeighbor(point52);
  point53.addNeighbor(point54);
  point54.addNeighbor(point46);
  point54.addNeighbor(point53);
}

} // namespace game