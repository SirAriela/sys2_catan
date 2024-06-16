#include "Map.hpp"
#include "Building.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "Road.hpp"
#include "Robber.hpp"
#include "Tile.hpp"

namespace game {
Map *Map::instance = nullptr;

Map::Map() {

  players = {};
  tiles = {};
  roadsInMap = {};
  turn = 2;



  // Crate Tiles for map
  Tile *tile1 = new Tile(Resource::Iron, 0, 10);
  Tile *tile2 = new Tile(Resource::Wool, 1, 2);
  Tile *tile3 = new Tile(Resource::Wood, 2, 9);
  Tile *tile4 = new Tile(Resource::Wheat, 3, 12);
  Tile *tile5 = new Tile(Resource::Brick, 4, 6);
  Tile *tile6 = new Tile(Resource::Wool, 5, 4);
  Tile *tile7 = new Tile(Resource::Brick, 6, 10);
  Tile *tile8 = new Tile(Resource::Wheat, 7, 9);
  Tile *tile9 = new Tile(Resource::Wood, 8, 11);
  Tile *tile10 = new Tile(Resource::None, 9, 0);
  Tile *tile11 = new Tile(Resource::Wood, 10, 3);
  Tile *tile12 = new Tile(Resource::Iron, 11, 8);
  Tile *tile13 = new Tile(Resource::Wood, 12, 8);
  Tile *tile14 = new Tile(Resource::Iron, 13, 3);
  Tile *tile15 = new Tile(Resource::Wheat, 14, 4);
  Tile *tile16 = new Tile(Resource::Wool, 15, 5);
  Tile *tile17 = new Tile(Resource::Brick, 16, 5);
  Tile *tile18 = new Tile(Resource::Wheat, 17, 6);
  Tile *tile19 = new Tile(Resource::Wool, 18, 11);

 robber = new Robber(tile10);

  addTile(tile1);
  addTile(tile2);
  addTile(tile3);
  addTile(tile4);
  addTile(tile5);
  addTile(tile6);
  addTile(tile7);
  addTile(tile8);
  addTile(tile9);
  addTile(tile10);
  addTile(tile11);
  addTile(tile12);
  addTile(tile13);
  addTile(tile14);
  addTile(tile15);
  addTile(tile16);
  addTile(tile17);
  addTile(tile18);
  addTile(tile19);

  // create Point*s for map
  Point* point1 = new Point(BuildingType::None);
    point1->addTile(tile1);
    addPoint(point1);

    Point* point2 = new Point(BuildingType::None);
    point2->addTile(tile1);
    addPoint(point2);

    Point* point3 = new Point(BuildingType::None);
    point3->addTile(tile1);
    point3->addTile(tile2);
    addPoint(point3);

    Point* point4 = new Point(BuildingType::None);
    point4->addTile(tile2);
    addPoint(point4);

    Point* point5 = new Point(BuildingType::None);
    point5->addTile(tile2);
    point5->addTile(tile3);
    addPoint(point5);

    Point* point6 = new Point(BuildingType::None);
    point6->addTile(tile3);
    addPoint(point6);

    Point* point7 = new Point(BuildingType::None);
    point7->addTile(tile3);
    point7->addTile(tile4);
    addPoint(point7);

    Point* point8 = new Point(BuildingType::None);
    point8->addTile(tile4);
    addPoint(point8);

    Point* point9 = new Point(BuildingType::None);
    point9->addTile(tile1);
    point9->addTile(tile4);
    addPoint(point9);

    Point* point10 = new Point(BuildingType::None);
    point10->addTile(tile1);
    point10->addTile(tile4);
    point10->addTile(tile5);
    addPoint(point10);

    Point* point11 = new Point(BuildingType::None);
    point11->addTile(tile1);
    point11->addTile(tile2);
    point11->addTile(tile5);
    addPoint(point11);

    Point* point12 = new Point(BuildingType::None);
    point12->addTile(tile2);
    point12->addTile(tile5);
    point12->addTile(tile6);
    addPoint(point12);

    Point* point13 = new Point(BuildingType::None);
    point13->addTile(tile2);
    point13->addTile(tile3);
    point13->addTile(tile6);
    addPoint(point13);

    Point* point14 = new Point(BuildingType::None);
    point14->addTile(tile3);
    point14->addTile(tile6);
    point14->addTile(tile7);
    addPoint(point14);

    Point* point15 = new Point(BuildingType::None);
    point15->addTile(tile3);
    point15->addTile(tile7);
    addPoint(point15);

    Point* point16 = new Point(BuildingType::None);
    point16->addTile(tile7);
    addPoint(point16);

    Point* point17 = new Point(BuildingType::None);
    point17->addTile(tile8);
    addPoint(point17);

    Point* point18 = new Point(BuildingType::None);
    point18->addTile(tile4);
    point18->addTile(tile8);
    addPoint(point18);

    Point* point19 = new Point(BuildingType::None);
    point19->addTile(tile4);
    point19->addTile(tile8);
    point19->addTile(tile9);
    addPoint(point19);

    Point* point20 = new Point(BuildingType::None);
    point20->addTile(tile4);
    point20->addTile(tile5);
    point20->addTile(tile9);
    addPoint(point20);

    Point* point21 = new Point(BuildingType::None);
    point21->addTile(tile5);
    point21->addTile(tile9);
    point21->addTile(tile10);
    addPoint(point21);

    Point* point22 = new Point(BuildingType::None);
    point22->addTile(tile5);
    point22->addTile(tile6);
    point22->addTile(tile10);
    addPoint(point22);

    Point* point23 = new Point(BuildingType::None);
    point23->addTile(tile6);
    point23->addTile(tile10);
    point23->addTile(tile11);
    addPoint(point23);

    Point* point24 = new Point(BuildingType::None);
    point24->addTile(tile6);
    point24->addTile(tile7);
    point24->addTile(tile11);
    addPoint(point24);

    Point* point25 = new Point(BuildingType::None);
    point25->addTile(tile7);
    point25->addTile(tile11);
    point25->addTile(tile12);
    addPoint(point25);

    Point* point26 = new Point(BuildingType::None);
    point26->addTile(tile7);
    point26->addTile(tile12);
    addPoint(point26);

    Point* point27 = new Point(BuildingType::None);
    point27->addTile(tile12);
    addPoint(point27);

    Point* point28 = new Point(BuildingType::None);
    point28->addTile(tile8);
    addPoint(point28);

    Point* point29 = new Point(BuildingType::None);
    point29->addTile(tile8);
    point29->addTile(tile13);
    addPoint(point29);

    Point* point30 = new Point(BuildingType::None);
    point30->addTile(tile8);
    point30->addTile(tile9);
    point30->addTile(tile13);
    addPoint(point30);

    Point* point31 = new Point(BuildingType::None);
    point31->addTile(tile9);
    point31->addTile(tile13);
    point31->addTile(tile14);
    addPoint(point31);

    Point* point32 = new Point(BuildingType::None);
    point32->addTile(tile9);
    point32->addTile(tile10);
    point32->addTile(tile14);
    addPoint(point32);

    Point* point33 = new Point(BuildingType::None);
    point33->addTile(tile10);
    point33->addTile(tile14);
    point33->addTile(tile15);
    addPoint(point33);

    Point* point34 = new Point(BuildingType::None);
    point34->addTile(tile10);
    point34->addTile(tile11);
    point34->addTile(tile15);
    addPoint(point34);

    Point* point35 = new Point(BuildingType::None);
    point35->addTile(tile11);
    point35->addTile(tile15);
    point35->addTile(tile16);
    addPoint(point35);

    Point* point36 = new Point(BuildingType::None);
    point36->addTile(tile11);
    point36->addTile(tile12);
    point36->addTile(tile16);
    addPoint(point36);

    Point* point37 = new Point(BuildingType::None);
    point37->addTile(tile12);
    point37->addTile(tile16);
    point37->addTile(tile17);
    addPoint(point37);

    Point* point38 = new Point(BuildingType::None);
    point38->addTile(tile12);
    point38->addTile(tile17);
    addPoint(point38);

    Point* point39 = new Point(BuildingType::None);
    point39->addTile(tile17);
    addPoint(point39);

    Point* point40 = new Point(BuildingType::None);
    point40->addTile(tile13);
    addPoint(point40);

    Point* point41 = new Point(BuildingType::None);
    point41->addTile(tile13);
    point41->addTile(tile18);
    addPoint(point41);

    Point* point42 = new Point(BuildingType::None);
    point42->addTile(tile13);
    point42->addTile(tile14);
    point42->addTile(tile18);
    addPoint(point42);

    Point* point43 = new Point(BuildingType::None);
    point43->addTile(tile14);
    point43->addTile(tile18);
    point43->addTile(tile19);
    addPoint(point43);

    Point* point44 = new Point(BuildingType::None);
    point44->addTile(tile14);
    point44->addTile(tile15);
    point44->addTile(tile19);
    addPoint(point44);

    Point* point45 = new Point(BuildingType::None);
    point45->addTile(tile15);
    point45->addTile(tile19);
    addPoint(point45);

    Point* point46 = new Point(BuildingType::None);
    point46->addTile(tile15);
    point46->addTile(tile16);
    addPoint(point46);

    Point* point47 = new Point(BuildingType::None);
    point47->addTile(tile16);
    point47->addTile(tile17);
    addPoint(point47);

    Point* point48 = new Point(BuildingType::None);
    point48->addTile(tile17);
    addPoint(point48);

    Point* point49 = new Point(BuildingType::None);
    point49->addTile(tile18);
    addPoint(point49);

    Point* point50 = new Point(BuildingType::None);
    point50->addTile(tile18);
    point50->addTile(tile19);
    addPoint(point50);

    Point* point51 = new Point(BuildingType::None);
    point51->addTile(tile19);
    addPoint(point51);

    Point* point52 = new Point(BuildingType::None);
    point52->addTile(tile19);
    addPoint(point52);

    Point* point53 = new Point(BuildingType::None);
    point53->addTile(tile16);
    point53->addTile(tile19);
    addPoint(point53);

    Point* point54 = new Point(BuildingType::None);
    point54->addTile(tile16);
    addPoint(point54);

  // build the neighbors
  point1->addNeighbor(point2);
  point1->addNeighbor(point9);
  point2->addNeighbor(point1);
  point2->addNeighbor(point3);
  point3->addNeighbor(point2);
  point3->addNeighbor(point4);
  point3->addNeighbor(point11);
  point4->addNeighbor(point3);
  point4->addNeighbor(point5);
  point5->addNeighbor(point4);
  point5->addNeighbor(point6);
  point5->addNeighbor(point13);
  point6->addNeighbor(point5);
  point6->addNeighbor(point7);
  point7->addNeighbor(point6);
  point7->addNeighbor(point15);
  point8->addNeighbor(point9);
  point8->addNeighbor(point18);
  point9->addNeighbor(point1);
  point9->addNeighbor(point8);
  point9->addNeighbor(point10);
  point10->addNeighbor(point9);
  point10->addNeighbor(point11);
  point10->addNeighbor(point20);
  point11->addNeighbor(point3);
  point11->addNeighbor(point10);
  point11->addNeighbor(point12);
  point12->addNeighbor(point11);
  point12->addNeighbor(point13);
  point12->addNeighbor(point22);
  point13->addNeighbor(point5);
  point13->addNeighbor(point12);
  point13->addNeighbor(point14);
  point14->addNeighbor(point13);
  point14->addNeighbor(point15);
  point14->addNeighbor(point24);
  point15->addNeighbor(point7);
  point15->addNeighbor(point14);
  point15->addNeighbor(point16);
  point16->addNeighbor(point15);
  point16->addNeighbor(point26);
  point17->addNeighbor(point18);
  point17->addNeighbor(point28);
  point18->addNeighbor(point8);
  point18->addNeighbor(point17);
  point18->addNeighbor(point19);
  point19->addNeighbor(point18);
  point19->addNeighbor(point20);
  point19->addNeighbor(point30);
  point20->addNeighbor(point10);
  point20->addNeighbor(point19);
  point20->addNeighbor(point21);
  point21->addNeighbor(point20);
  point21->addNeighbor(point22);
  point21->addNeighbor(point32);
  point22->addNeighbor(point12);
  point22->addNeighbor(point21);
  point22->addNeighbor(point23);
  point23->addNeighbor(point22);
  point23->addNeighbor(point24);
  point23->addNeighbor(point34);
  point24->addNeighbor(point14);
  point24->addNeighbor(point23);
  point24->addNeighbor(point25);
  point25->addNeighbor(point24);
  point25->addNeighbor(point26);
  point25->addNeighbor(point36);
  point26->addNeighbor(point16);
  point26->addNeighbor(point25);
  point26->addNeighbor(point27);
  point27->addNeighbor(point26);
  point27->addNeighbor(point38);
  point28->addNeighbor(point17);
  point28->addNeighbor(point29);
  point29->addNeighbor(point28);
  point29->addNeighbor(point30);
  point29->addNeighbor(point39);
  point30->addNeighbor(point19);
  point30->addNeighbor(point29);
  point30->addNeighbor(point31);
  point31->addNeighbor(point30);
  point31->addNeighbor(point32);
  point31->addNeighbor(point41);
  point32->addNeighbor(point21);
  point32->addNeighbor(point31);
  point32->addNeighbor(point33);
  point33->addNeighbor(point32);
  point33->addNeighbor(point34);
  point33->addNeighbor(point43);
  point34->addNeighbor(point23);
  point34->addNeighbor(point33);
  point34->addNeighbor(point35);
  point35->addNeighbor(point34);
  point35->addNeighbor(point36);
  point35->addNeighbor(point45);
  point36->addNeighbor(point25);
  point36->addNeighbor(point35);
  point36->addNeighbor(point37);
  point37->addNeighbor(point36);
  point37->addNeighbor(point38);
  point37->addNeighbor(point47);
  point38->addNeighbor(point27);
  point38->addNeighbor(point37);
  point39->addNeighbor(point29);
  point39->addNeighbor(point40);
  point40->addNeighbor(point39);
  point40->addNeighbor(point41);
  point40->addNeighbor(point48);
  point41->addNeighbor(point31);
  point41->addNeighbor(point40);
  point41->addNeighbor(point42);
  point42->addNeighbor(point41);
  point42->addNeighbor(point43);
  point42->addNeighbor(point50);
  point43->addNeighbor(point33);
  point43->addNeighbor(point42);
  point43->addNeighbor(point44);
  point44->addNeighbor(point43);
  point44->addNeighbor(point45);
  point44->addNeighbor(point52);
  point45->addNeighbor(point35);
  point45->addNeighbor(point44);
  point45->addNeighbor(point46);
  point46->addNeighbor(point45);
  point46->addNeighbor(point47);
  point46->addNeighbor(point54);
  point47->addNeighbor(point37);
  point47->addNeighbor(point46);
  point48->addNeighbor(point40);
  point48->addNeighbor(point49);
  point49->addNeighbor(point48);
  point49->addNeighbor(point50);
  point50->addNeighbor(point49);
  point50->addNeighbor(point51);
  point51->addNeighbor(point50);
  point51->addNeighbor(point52);
  point52->addNeighbor(point51);
  point52->addNeighbor(point53);
  point53->addNeighbor(point52);
  point53->addNeighbor(point54);
  point54->addNeighbor(point46);
  point54->addNeighbor(point53);

}

} // namespace game