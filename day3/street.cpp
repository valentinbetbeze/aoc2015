#include "street.h"

#include <cstddef>

House &Street::enter_house(const Pos p)
{
    for (House &h : _houses)
    {
        if (p.second == h.get_pos().second)
        {
            // Santa's already visited this house
            return h;
        }
    }

    // New house! Add it to the map
    if (p.second < _houses.front().get_pos().second)
    {
        _houses.push_front(House(p));
        return _houses.front();
    }
    else
    {
        _houses.push_back(House(p));
        return _houses.back();
    }
}
