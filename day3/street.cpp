#include "street.h"

House &Street::operator[](int y)
{
    for (House &h : _houses)
    {
        if (y == h.get_pos().second)
        {
            // Santa's already visited this house
            return h;
        }
    }

    // New house! Add it to the map
    if (y < _houses.front().get_pos().second)
    {
        _houses.push_front(House({_address, y}));
        return _houses.front();
    }
    else
    {
        _houses.push_back(House({_address, y}));
        return _houses.back();
    }
}
