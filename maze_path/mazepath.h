#ifndef _MAZEPATH_H_
#define _MAZEPATH_H_

#include <vector>
#include <stack>
#include <iostream>

namespace restonce
{
    constexpr int ptSpace=0, ptWall=1, ptArrived=2, ptIvalidate=3;	// define position type
    typedef int PositionType;

class Map
{
public :
    Map(int w_, int h_, const std::vector<PositionType>& pt ) : w(w_), h(h_), data(pt)
    {
        data.resize(w * h);	// init map
    }
    bool position(int x,int y, PositionType pt)		// set the (x, y) as pt position type	and return true;
    {							// if (x, y) is ptIvalidate , return false;
        if ( x< 0 || y<0 || x>= w || y>= h ) {
            return false;
        }
        data[y*w + x] = pt;
        return true;
    }
    PositionType position(int x,int y) const	// get position type of (x, y)
    {
        if ( x< 0 || y<0 || x>= w || y>= h ) {
            return ptIvalidate;
        }
        return data[y*w + x];
    }
    int width() const	// read width
    {
        return w;
    }
    int height() const	// read height
    {
        return h;
    }
    void print()	// print map to scrren, main-use debug
    {
        int i =0;

        for (auto x: data) {
            std::cout << x ;
            ++i;
            if ( i % w == 0) {
                std::cout << std::endl;
            }
        }
    }
private :
    int w,h;
    std::vector<PositionType> data;
};
namespace Direction
{
struct Increase {
    int x, y;
};
typedef   int  		DirectionType;	
constexpr DirectionType 	dirUP=0, dirRIGHT=1, dirDOWN=2, dirLEFT=3, dirEND=4;	
constexpr Increase increse[] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };	
}

class Position
{
public :
    Position(int x_,int y_) : x(x_), y(y_), direction(Direction::dirUP) {}
    bool canArrive(const Map& m) const	// judge whether this position is ptSpace
    {
        return m.position(x, y) == ptSpace;
    }
    bool operator== (const Position& rp) const
    {
        return  x==rp.x && y==rp.y;
    }
    Position nextPosition() const	// get the next position of this position
    {
        return Position( x + Direction::increse[direction].x, y + Direction::increse[direction].y );
    }
    bool endDirection() const
    {
        return direction >= Direction::dirEND;
    }
    bool turnDirection()	// turn the position direction to next , 
    {				// if direction to end , return false;
        if ( endDirection() ) {
            return false;
        }
        ++ direction;
        return true;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    void print() const {
        std::cout << "(" << x << "," << y << ")" << std::endl;
    }
private :
    int x, y;
    Direction::DirectionType direction;
};
std::vector<Position> mazePath(Map map,const Position& begin, const Position& end)
{
    std::vector<Position> ps;
    Position currentPosition(begin);

    do {
        if ( currentPosition.canArrive(map) ) {
            ps.push_back(currentPosition);
            map.position(currentPosition.getX(), currentPosition.getY(), ptArrived);

            if ( currentPosition == end) {
                break;
            }
            currentPosition = currentPosition.nextPosition();
        } else {
            if (ps.empty() == false) {
                if (ps.back().turnDirection() == true) {
                    currentPosition = ps.back().nextPosition();
                } else {
                    ps.pop_back();
                    while ( ps.empty() == false) {
                        if (ps.back().turnDirection() == true) {
                            currentPosition = ps.back().nextPosition();
                            break;
                        }
                        ps.pop_back();
                    }
                }
            }
        }

    } while ( ps.empty() == false);

    return ps;
}
}

#endif
