#ifndef DEVELOPMENT_CARD_HPP
#define DEVELOPMENT_CARD_HPP

namespace game {

enum class DevelopmentCardType {
    Knight,
    VictoryPoint,
    RoadBuilding,
    Monopoly,
    YearOfPlenty
};

class DevelopmentCard {
public:
    DevelopmentCard(DevelopmentCardType type) : type(type) {}

    DevelopmentCardType getType() const { return type; }

private:
    DevelopmentCardType type;
};

}

#endif // DEVELOPMENT_CARD_HPP
