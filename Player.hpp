#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Resource.hpp"
#include <map>
#include <vector>

class Player {
public:
    Player(int id) : id(id), victoryPoints(0) {}
    int getId() const { return id; }
    int getVictoryPoints() const { return victoryPoints; }
    void addResource(Resource resource, int amount);
    void useResource(Resource resource, int amount);
    bool hasResources(const std::map<Resource, int>& cost) const;
    void addVictoryPoints(int points) { victoryPoints += points; }

private:
    int id;
    int victoryPoints;
    std::map<Resource, int> resources;
};

#endif // PLAYER_HPP
