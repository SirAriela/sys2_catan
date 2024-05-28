#ifndef BUILDING_HPP
#define BUILDING_HPP

enum class BuildingType {
    Settlement,
    City
};

class Building {
public:
    Building(BuildingType type) : type(type) {}
    BuildingType getType() const { return type; }

private:
    BuildingType type;
};

#endif
