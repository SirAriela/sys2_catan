// Dice.cpp
#include "Dice.hpp"
#include <cstdlib>
#include <ctime>

namespace game {
Dice::Dice() { std::srand(std::time(nullptr)); }

int Dice::roll() {
  // Generate random numbers between 1 and 6 for two dice
  int diceValue1 = std::rand() % 6 + 1;
  int diceValue2 = std::rand() % 6 + 1;
  return diceValue1 + diceValue2;
}
} // namespace game
