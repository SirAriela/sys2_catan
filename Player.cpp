
#include "Player.hpp"

namespace game
{

    // adds resources to the player
    void Player::addResource(Resource resource, int amount)
    {
        resources[resource] += amount;
    }

    // removes resources from the player when on use
    void Player::useResource(Resource resource, int amount)
    {
        resources[resource] -= amount;
    }

    // checks if the player has enough resources to build a settlement or city or road
    bool Player::hasResources(const std::map<Resource, int> &cost) const
    {
        for (const auto &pair : cost)
        {
            auto it = resources.find(pair.first);
            if (it == resources.end() || it->second < pair.second)
            {
                return false;
            }
        }
        return true;
    }
    void Player::addDevelopmentCard(DevelopmentCard card)
    {
        developmentCards.push_back(card);
    }
} // namespace game
