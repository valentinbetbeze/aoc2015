#include "street.h"

#include <deque>
#include <cstddef>

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

    std::deque<Street> streets;
    int start = 0;
    int num_houses = 0;
};


#endif    // _MAP_H_
