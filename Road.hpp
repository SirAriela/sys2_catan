#ifndef ROAD_HPP
#define ROAD_HPP

namespace game
{
    class Player;
    class Point;
    class Road{
    public:
        // create a road
        Road(Point *point1, Point *point2, Player *Player) : point1(point1), point2(point2),owner(Player) {}
        // get the points the road is on
        Point *getPoint1() const { return point1; }
        Point *getPoint2() const { return point2; }

    private:
        Point *point1;
        Point *point2;
        Player *owner;
    };
}

#endif