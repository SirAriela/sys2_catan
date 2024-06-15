// Dice.cpp
#include "Dice.hpp"
#include <cstdlib>
#include <ctime>

namespace game {
 int Dice::roll() {
  // Generate random numbers between 1 and 6 for two dice
  srand(time(0));
  int dice1 = (rand() % 6) + 1;
  int dice2 = (rand() % 6) + 1;
  return dice1 + dice2;
 }
} // namespace game
