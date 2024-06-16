// 206862666
// Ariela

#include "Deck.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include <cstddef>
#include <iostream>
#include <string>

using namespace game;

int main() {
  try {
    srand(time(0));
    game::Map *map = game::Map::getInstance();
    Deck *deck = Deck::getInstance();

    if (!map) {
      std::cerr << "Failed to get map instance." << std::endl;
      return 1; // Or handle error appropriately
    }

    game::Player player1(0, "Alice");
    game::Player player2(1, "Bob");
    game::Player player3(2, "Amy");

    map->addPlayer(&player1);
    map->addPlayer(&player2);
    map->addPlayer(&player3);

    map->nextPlayer();

    size_t point1 = 23;
    size_t point2 = 29;
    cout << "player " << player1.getName() << " turn" << endl;
    player1.addSettlement(map->getPoint(point1));
    player1.addRoad(map->getPoint(point1), map->getPoint(point1 + 1));
    player1.addSettlement(map->getPoint(point2));
    player1.addRoad(map->getPoint(point2), map->getPoint(point2 + 1));
    cout << "player has " << player1.getSettlements() << " settelments and "
         << player1.getRoads() << " roads" << endl;
    player1.endTurn();

    size_t point3 = 41;
    size_t point4 = 44;
    cout << "player " << player2.getName() << " turn" << endl;
    player2.addSettlement(map->getPoint(point3));
    player2.addRoad(map->getPoint(point3), map->getPoint(point3 - 1));
    player2.addSettlement(map->getPoint(point4));
    player2.addRoad(map->getPoint(point4), map->getPoint(point4 + 1));
    player2.endTurn();

    size_t point5 = 1;
    size_t point6 = 49;
    cout << "player " << player3.getName() << " turn" << endl;
    player3.addSettlement(map->getPoint(point5));
    player3.addRoad(map->getPoint(point5), map->getPoint(point5 - 1));
    player3.addSettlement(map->getPoint(point6));
    player3.addRoad(map->getPoint(point6), map->getPoint(point6 + 1));
    cout << "player has " << player1.getSettlements() << " settelments and "
         << player1.getRoads() << " roads" << endl;
    player3.endTurn();

    cout << "player " << player1.getName() << " turn" << endl;
    player1.rollDice();
   

    player1.addDevelopmentCard(deck->drawCard());
    player1.printPoints();
    player1.endTurn();
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
// namespace game