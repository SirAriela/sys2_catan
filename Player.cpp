
#include "Player.hpp"
#include "Map.hpp"
#include "Road.hpp"

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

    // add the card to the player
    developmentCards.push_back(card);

    // if the card is a victory point card, add a victory point
    if (card == DevelopmentCardType::VictoryPoint) {
      victoryPoints++;
    }
    if (card == DevelopmentCardType::Knight) {
      // add the knight to the player
      knights++;
    }

  } else {
    std::__throw_runtime_error("Not enough resources");
  }
}

// add a settlement to the player
void Player::addSettlement(Point *point) {

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
}

// add a city to the player
void Player::addCity(game::Point *point) {
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

// add a road to the player
void Player::addRoad(Point *point1, Point *point2) {
  game::Map *instance = Map::getInstance();
  bool hasRoad = false;

  for (auto r : instance->getRoadInMap()) {
    if (r.getPoint1() == point1 && r.getPoint2() == point2) {
      std::__throw_runtime_error("Road already exists");
    }
  }
  for (auto r : instance->getRoadInMap()) {
    if (r.getPoint1() == point2 && r.getPoint2() == point1) {
      std::__throw_runtime_error("Road already exists");
    }
  }
  // check if there is a road attached to the point
  for (auto r : instance->getRoadInMap()) {
    if (r.getOwner() == this) {
      if ((r.getPoint1() == point1 && r.getPoint2() != point2) ||
          (r.getPoint2() == point1 && r.getPoint1() != point2) ||
          (r.getPoint1() == point2 && r.getPoint2() != point1) ||
          (r.getPoint2() == point2 && r.getPoint1() != point1)) {
        if (r.getOwner() == this) {
          hasRoad = true;
        }
      }
    }
  }
  if (!(point1->getOwner() != this && point2->getOwner() != this))
    hasRoad = true;

  if (!hasRoad) {
    std::__throw_runtime_error("No road attached to the point and the point is not owned by the player");
  }
  if (hasResources(ROAD_COST)) {
    // buy the road
    useResource(Resource::Wood, 1);
    useResource(Resource::Brick, 1);

    // add the road to the player
    Road *road = new Road(point1, point2, this);
    Road *otherway = new Road(point2, point1, this);
    roads++;

    instance->addRoadInMap(*road);

  } else {
    __throw_runtime_error("Not enough resources");
  }
}
}; // namespace game
