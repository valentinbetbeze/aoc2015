#include <deque>

#include "street.h"

#ifndef _MAP_H_
#define _MAP_H_

class Map
{
public:
    Map() : streets {Street()} {}

    std::deque<Street> streets;
    int start = 0;
    int num_houses = 0;
};

#endif // _MAP_H_
