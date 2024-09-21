#include "street.h"

#include <cstddef>
#include <deque>

#ifndef _MAP_H_
#define _MAP_H_

class Map
{
public:
    Map() : streets {Street()} {}

    House &enter_house(const Pos p)
    {
        return streets[static_cast<size_t>(p.first + start)][p.second];
    }
    // Map is only an interface and shall not hide its data from Santa
    std::deque<Street> streets;
    int start = 0;
    int num_houses = 0;
};


#endif    // _MAP_H_
