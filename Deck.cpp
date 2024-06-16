#include "Deck.hpp"
#include <algorithm>
#include <random>
#include <stdexcept>

namespace game {

// Initialize the static instance pointer to nullptr
Deck* Deck::instance = nullptr;

Deck::Deck() {
  // knights
  for (int i = 0; i < 3; ++i)
    cards.push_back(game::DevelopmentCardType::Knight);
  // victory points
  for (int i = 0; i < 5; ++i)
    cards.push_back(game::DevelopmentCardType::VictoryPoint);
  // moonopoly
  for (int i = 0; i < 2; ++i)
    cards.push_back(game::DevelopmentCardType::Monopoly);
  // year of plenty
  for (int i = 0; i < 2; ++i)
    cards.push_back(game::DevelopmentCardType::YearOfPlenty);
  // road building
  for (int i = 0; i < 2; ++i)
    cards.push_back(game::DevelopmentCardType::RoadBuilding);

  shuffleDeck();
}

Deck* Deck::getInstance() {
  // If the instance doesn't exist, create it
  if (!instance) {
    instance = new Deck();
  }
  return instance;
}

DevelopmentCardType Deck::drawCard() {
  if (cards.empty())
    throw std::runtime_error("No cards left in the deck");
  DevelopmentCardType card = cards.back();
  cards.pop_back();
  return card;
}

void Deck::shuffleDeck() {
  std::shuffle(cards.begin(), cards.end(), std::random_device());
}

} // namespace game
