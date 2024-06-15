#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "DevelopmentCard.hpp"
#include "Point.hpp"
#include "Resource.hpp"
#include <map>
#include <string>
#include <vector>

#pragma once

namespace game {
class Point;
class Road;

class Player {
public:
  // Create a player
  Player(int id, std::string name)
      : id(id), name(name), victoryPoints(0), roads(0), settlements(0),
        cities(0), developmentCards({}), knights(0),isPlayig(false) {
    for (auto i : ROAD_COST) {
      addResource(i.first, i.second);
    }
    for (auto i : ROAD_COST) {
      addResource(i.first, i.second);
    }
    for (auto i : SETTLEMENT_COST) {
      addResource(i.first, i.second);
    }
    for (auto i : SETTLEMENT_COST) {
      addResource(i.first, i.second);
    }
  }
  Player() = default;
  ~Player() = default;
  //-------------------------------------------------------------------------

  // getters
  // get the id of the player
  int getId() const { return id; }
  // get the victory points of the player
  int getVictoryPoints() const { return victoryPoints; }
  // get development cards of the player
  const std::vector<DevelopmentCardType> &getDevelopmentCards() const {
    return developmentCards;
  }
  // get name
  std::string getName() const { return name; }
  //get number of roads
  int getRoads() const { return roads; }
  //get number of settlements
  int getSettlements() const { return settlements; }
  //get number of cities
  int getCities() const { return cities; }
  // get number of knights
  int getKnights() const { return knights; }
  //get is playing
  bool getIsPlaying() const { return isPlayig; }

  //-------------------------------------------------------------------------

  // adders and substractors
  //  add resources to the player
  void addResource(Resource resource, int amount);
  // remove resources from the player when on use
  void useResource(Resource resource, int amount);
  // checks if the player has enough resources to build a settlement or city or
  // road or buy a development card
  bool hasResources(const std::map<Resource, int> &cost) const;
  // add victory points to the player
  void addVictoryPoints(int points) { victoryPoints += points; }
  // add development card to the player
  void addDevelopmentCard(DevelopmentCardType card);
  // add settlement to the tile
  void addSettlement(Point *point);
  // add city to the tile
  void addCity(Point *point);
  // add road to the tile
  void addRoad(Point *point1, Point *point2);
  //set the player to playing
  void setPlaying(bool playing) { isPlayig = playing; }

  //--------------------------- costs ---------------------------
  const std::map<Resource, int> ROAD_COST = {{Resource::Wood, 1},
                                             {Resource::Brick, 1}};

  const std::map<Resource, int> SETTLEMENT_COST = {{Resource::Wood, 1},
                                                   {Resource::Brick, 1},
                                                   {Resource::Wool, 1},
                                                   {Resource::Wheat, 1}};

  const std::map<Resource, int> CITY_COST = {{Resource::Wheat, 2},
                                             {Resource::Iron, 3}};

  const std::map<Resource, int> DEVELOPMENT_CARD_COST = {
      {Resource::Wool, 1}, {Resource::Wheat, 1}, {Resource::Iron, 1}};

  //-------------------------------------------------------------------------
private:
  int id;            // id number
  std::string name;  // name of the player
  int victoryPoints; // number of victory points the player has
  // which roads the player has
  int roads;
  int settlements;
  int cities;
  std::map<Resource, int> resources; // what resources the player has
  std::vector<DevelopmentCardType>
      developmentCards; // what development cards the player has
  int knights;          // number of knights the player has
  bool isPlayig;        // if the player is playing
};

} // namespace game

#endif
