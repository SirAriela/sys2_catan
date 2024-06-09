#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Recources.hpp"
#include <map>
#include <vector>
#include "Point.hpp"
#include "DevelopmentCard.hpp"

namespace game
{

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
        void addDevelopmentCard(DevelopmentCard card);
        const std::vector<DevelopmentCard> &getDevelopmentCards() const { return developmentCards; }

    private:
        int id;
        int victoryPoints;
        Point** points; //which points the player has a city or a settelment
        std::map<Resource, int> resources;
        std::vector<DevelopmentCard> developmentCards;
    };

} // namespace game

#endif // PLAYER_HPP
