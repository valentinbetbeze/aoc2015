#include "house.h"
#include "map.h"

#include <deque>
#include <iostream>

#ifndef _SANTA_H_
#define _SANTA_H_


class Santa
{
public:
    enum Below
    {
        HOUSE_BELOW,
        JUST_SNOW_BELOW,
    };

    Santa() : _pos {0, 0}
    {
        // Santa is generous: he drops a present as soon as he arrives
        drop_present();
    }

    Below move(const char dir);
    void drop_present();
    int get_number_visited_houses()
    {
        return map.num_houses;
    }

private:
    Pos _pos;
    int _drop = 0;
    // Santa always keeps the map of the town with him
    static Map map;
};


#endif    // _SANTA_H_
