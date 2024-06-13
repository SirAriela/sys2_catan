#ifndef ROAD_HPP
#define ROAD_HPP

namespace game
{
    class Player;
    class Point;
    class Road{
    public:
        // create a road
        Road(Player *player, Point *point1, Point *point2) : owner(player), point1(point1), point2(point2) {}
        // get the player who owns the road
        Player *getPlayer() const { return owner; }
        // get the points the road is on
        Point *getPoint1() const { return point1; }
        Point *getPoint2() const { return point2; }

    private:
        Player *owner;
        Point *point1;
        Point *point2;
    };
}

#endif