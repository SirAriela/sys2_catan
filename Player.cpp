
#include "Player.hpp"
#include "Logic.hpp"
#include "Map.hpp"
#include "Road.hpp"
#include <iostream>

namespace game {

// adds resources to the player
void Player::addResource(Resource resource, int amount) {
  resources[resource] += amount;
}

// removes resources from the player when on use
void Player::useResource(Resource resource, int amount) {
  resources[resource] -= amount;
}

// checks if the player has enough resources to build a settlement/city/road or
// buy a development card
bool Player::hasResources(const std::map<Resource, int> &cost) const {
  for (const auto &pair : cost) {
    auto it = resources.find(pair.first);
    if (it == resources.end() || it->second < pair.second) {
      return false;
    }
  }
  return true;
}

// add a development card to the player
void Player::addDevelopmentCard(DevelopmentCardType card) {
  if (hasResources(DEVELOPMENT_CARD_COST)) {
    // remove the resources from the player
    useResource(Resource::Wool, 1);
    useResource(Resource::Wheat, 1);
    useResource(Resource::Iron, 1);

    cout << "player " << this->getName() << " got a development card" << endl;

    if (card == DevelopmentCardType::Knight) {
      knights++;
      if (knights >= 3) {
        victoryPoints += 2;
      }
    }
    if (card == DevelopmentCardType::VictoryPoint) {
      victoryPoints++;
      cout << "player " << this->getName() << " got a victory point card"
           << endl;
    }
    if (card == DevelopmentCardType::Monopoly) {
      cout << "player " << this->getName() << " got a monopoly card" << endl;
      monopoly++;
    }
    if (card == DevelopmentCardType::RoadBuilding) {
      cout << "player " << this->getName() << " got a road building card"
           << endl;
      roadBuilding++;
    }
    if (card == DevelopmentCardType::YearOfPlenty) {
      cout << "player " << this->getName() << " got a year of plenty card"
           << endl;
      yearOfPlenty++;
    }

    // add the card to the player
    developmentCards.push_back(card);

  } else {
    std::__throw_runtime_error("Not enough resources");
  }
}

// add a settlement to the player
void Player::addSettlement(Point *point) {
  if (this->getIsPlaying()) {
    if (point != nullptr) {

      // checks there is no building alredy on the point
      if (point->getBuilding() != BuildingType::None) {
        std::__throw_runtime_error("Point already has a building");

      } else {
        // checks if the player has enough resources to build a settlement
        if (hasResources(SETTLEMENT_COST)) {
          useResource(Resource::Wood, 1);
          useResource(Resource::Brick, 1);
          useResource(Resource::Wool, 1);
          useResource(Resource::Wheat, 1);

          // updates the tiles that the player has a settlement on
          std::vector<Tile *> tiles = point->getTiles();
          for (auto t : tiles) {
            t->addOccupant(this->getId());
          }

          // // updates the points that the player has a settlement on
          // points.push_back(*point);

          // updates the building type of the point
          point->SetBuilding(BuildingType::Settlement);

          point->setOwner(this);

          // updates the victory points of the player
          victoryPoints++;
          settlements++;
        } else {
          __throw_runtime_error("Not enough resources to buy a settlement");
        }
      }
    }
  } else {
    throw("not your turn to play " + this->getName());
  }
}

// add a city to the player
void Player::addCity(game::Point *point) {
  if (!this->getIsPlaying()) {
    throw("not your turn to play " + this->getName());
  }
  if (point->getBuilding() != BuildingType::Settlement) {
    std::__throw_runtime_error("Point doesn't have a settelment on it");

  } else if (point->getOwner() != this) {
    std::__throw_runtime_error(
        "you are trying to build a city on someone else's settlement");

  } else {
    if (hasResources(CITY_COST)) {
      // remove the resources from the player
      useResource(Resource::Wheat, 2);
      useResource(Resource::Iron, 3);

      // update the building type of the point
      point->SetBuilding(BuildingType::City);
      victoryPoints++;

    } else {
      std::__throw_runtime_error("Not enough resources to buy a city");
    }
  }
}

void Player::endTurn() {
  isPlayig = false;
  game::Map *instance = Map::getInstance();
  instance->nextPlayer();
}

// add a road to the player
void Player::addRoad(Point *point1, Point *point2) {
  if (!this->getIsPlaying()) {
    throw("not your turn to play " + this->getName());
  }
  game::Map *instance = Map::getInstance();
  bool hasRoad = false;

  for (auto r : instance->getRoadInMap()) {
    if (r->getPoint1() == point1 && r->getPoint2() == point2) {
      std::__throw_runtime_error("Road already exists");
    }
  }
  for (auto r : instance->getRoadInMap()) {
    if (r->getPoint1() == point2 && r->getPoint2() == point1) {
      std::__throw_runtime_error("Road already exists");
    }
  }
  // check if there is a road attached to the point
  for (auto r : instance->getRoadInMap()) {
    if (r->getOwner() == this) {
      if ((r->getPoint1() == point1 && r->getPoint2() != point2) ||
          (r->getPoint2() == point1 && r->getPoint1() != point2) ||
          (r->getPoint1() == point2 && r->getPoint2() != point1) ||
          (r->getPoint2() == point2 && r->getPoint1() != point1)) {
        if (r->getOwner() == this) {
          hasRoad = true;
        }
      }
    }
  }
  if (!(point1->getOwner() != this && point2->getOwner() != this))
    hasRoad = true;

  if (!hasRoad) {
    std::__throw_runtime_error("No road attached to the point and the point is "
                               "not owned by the player");
  }
  if (hasResources(ROAD_COST)) {
    // buy the road
    useResource(Resource::Wood, 1);
    useResource(Resource::Brick, 1);

    // add the road to the player
    Road *road = new Road(point1, point2, this);
    Road *otherway = new Road(point2, point1, this);
    roads++;

    instance->addRoadInMap(road);
    instance->addRoadInMap(otherway);

  } else {
    __throw_runtime_error("Not enough resources");
  }
}

// discard half of the resources
void Player::discardHalfResources() {
  int total = resources.size() / 2 ;
  for (auto resource : resources) {
    if (total > 0) {
      resources.erase(resource.first);
      total--;
    }
  }
 
}

// rolls the dice
void Player::rollDice() {
  if(!this->getIsPlaying()){
    throw("not your turn to play " + this->getName());
  }
  int roll = dice.roll();
  std::cout << "Rolled a " << roll << std::endl;
  if (roll != 7){
    Logic::getResorces(*Map::getInstance(), roll);
  }
  else{
    for(auto player : Map::getInstance()->getPlayers()){
      if(player->getResources().size() > 7){
        player->discardHalfResources();
      }
    }
  }
}
void Player::printPoints() {
  int victoryPointsFromDevCards = 0;
  for (auto card : developmentCards) {
    if (card == DevelopmentCardType::VictoryPoint) {
      victoryPointsFromDevCards += 1;
    }
  }
  cout << "player " << this->getName() << " has " << this->getRoads()
       << " roads" << endl;
  cout << "player has " << this->getVictoryPoints() << " victory points"
       << endl;
  if (settlements > 0) {
    cout << "because of settelments ";
  }
  if (cities > 0) {
    cout << "because of cities ";
  }
  if (victoryPointsFromDevCards > 0) {
    cout << "because of development cards ";
  }
  if (knights >= 3) {
    cout << "because of knights ";
  }

  cout << endl;
}

}; // namespace game
