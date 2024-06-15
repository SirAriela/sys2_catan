#include "Dice.hpp"

#include "Map.hpp"
#include "Player.hpp"
#include "Tile.hpp"

#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

using namespace game;

int main() {
  try {
    game::Dice dice;
    game::Map &map = game::Map::getInstance();

    game::Player player1(0, "Alice");
    game::Player player2(1, "Bob");
    game::Player player3(2, "Amy");

    map.addPlayer(&player1);
    map.addPlayer(&player2);
    map.addPlayer(&player3);
    
    size_t x = 14;
    game::Point* p = map.getPoint(x);
    
    std::cout << p->getOwner()->getName() << std::endl;
    for(auto t: p->getTile()){
      std::cout << "Tile " << t->getNumber() << " has " << t->getOccupants().size() << " occupants" << std::endl;
    }
    player1.addSettlement(map.getPoint(x));

    // player2.addSettlement(map.getPoint(x++));
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}