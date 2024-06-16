#ifndef DECK_HPP
#define DECK_HPP

#include "DevelopmentCard.hpp"
#include <vector>

namespace game {

class Deck {
public:
  Deck();
  //~Deck();

  static Deck* getInstance();

  DevelopmentCardType drawCard();
  void shuffleDeck();

  Deck(const Deck &) = delete;
  Deck &operator=(const Deck &) = delete;

private:
  std::vector<DevelopmentCardType> cards;
  static Deck* instance;
};

} // namespace game

#endif // DECK_HPP
