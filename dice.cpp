//206862666
//ariela goncherook

#include <cstdlib>
#include <ctime>

class Dice {
public:
  Dice() { std::srand(std::time(nullptr)); }
  int roll() { 
    // Generate random numbers between 1 and 6 for two dice
    int diceValue1 = std::rand() % 6 + 1;
    int diceValue2 = std::rand() % 6 + 1;
    return diceValue1 + diceValue2;
   }

};