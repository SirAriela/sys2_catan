#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Recources.hpp"
#include <map>
#include <vector>
#include "DevelopmentCard.hpp"
#include "Road.hpp"
#include "Point.hpp"

namespace game
{

    class Point;
    class Player
    {

    public:
        Player(int id) : id(id), victoryPoints(0) {}
        int getId() const { return id; }
        int getVictoryPoints() const { return victoryPoints; }
        void addResource(Resource resource, int amount);
        void useResource(Resource resource, int amount);
        bool hasResources(const std::map<Resource, int> &cost) const;
        void addVictoryPoints(int points) { victoryPoints += points; }
        void addDevelopmentCard(DevelopmentCardType card);
        const std::vector<DevelopmentCardType> &getDevelopmentCards() const { return developmentCards; }
        // add settlement to the tile
        void addSettlement(Point *point);
        // add city to the tile
        void addCity(Point *point);
        // add road to the tile
        void addRoad(Point *point1, Point *point2);

        //--------------------------- costs ---------------------------
        const std::map<Resource, int> ROAD_COST = {{Resource::Wood, 1}, {Resource::Brick, 1}};
        const std::map<Resource, int> SETTLEMENT_COST = {{Resource::Wood, 1}, {Resource::Brick, 1}, {Resource::Wool, 1}, {Resource::Wheat, 1}};
        const std::map<Resource, int> CITY_COST = {{Resource::Wheat, 2}, {Resource::Iron, 3}};
        const std::map<Resource, int> DEVELOPMENT_CARD_COST = {{Resource::Wool, 1}, {Resource::Wheat, 1}, {Resource::Iron, 1}};


    private:
        int id;
        int victoryPoints;
        std::vector<Point>points; // which points the player has a city or a settelment
        std::vector<Road> roads;  // which roads the player has
        std::map<Resource, int> resources;
        std::vector<DevelopmentCardType> developmentCards;
        int knights;//number of knights the player has
       
    };

} // namespace game

#endif // PLAYER_HPP
