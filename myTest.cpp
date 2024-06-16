
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Deck.hpp"
#include "Logic.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Robber.hpp"
#include "Tile.hpp"
#include "doctest.h"

using namespace game;

TEST_CASE("Testing you can make turn only in your turn") {

  // Create a player and tiles
  game::Player player1(0, "Alice");
  game::Player player2(1, "Bob");
  game::Player player3(2, "Bobby");

  game::Map *map = game::Map::getInstance();
  map->addPlayer(&player1);
  map->addPlayer(&player2);

  map->nextPlayer();

  CHECK_THROWS(player2.rollDice());
}

TEST_CASE("Testing Resource Collection") {
  // Create a map, player, and tiles

  game::Map *map = game::Map::getInstance();
  game::Player* player1 = map->getPlayers().at(0);
  Dice dice;
  int roll = dice.roll();
  
  // map->nextPlayer();
  player1->addSettlement(map->getPoint(11));
  player1->addRoad(map->getPoint(11), map->getPoint(12));

  if (roll == 2 || roll == 4) {
    int wool = player1->getResources().at(game::Resource::Wool);
    Logic::getResorces(*Map::getInstance(), roll);
    CHECK(player1->getResources().at(game::Resource::Wool) == wool + 1);
  }

  if (roll == 6) {
    int brick = player1->getResources().at(game::Resource::Brick);
    Logic::getResorces(*Map::getInstance(), roll);
    CHECK(player1->getResources().at(game::Resource::Brick) == brick + 1);
  }
  int wool = player1->getResources().at(game::Resource::Wool);
  Logic::getResorces(*Map::getInstance(), roll);
  CHECK_FALSE(player1->getResources().at(game::Resource::Brick) == wool + 1);
}
