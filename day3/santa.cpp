#include "santa.h"

#include <iostream>


Map Santa::map {};

Santa::Below Santa::move(const char c)
{
    switch (c)
    {
        case '>':
            _pos.first++;
            break;
        case '<':
            _pos.first--;
            break;
        case '^':
            _pos.second++;
            break;
        case 'v':
            _pos.second--;
            break;
        default:
            // Wrong input, or \n, or EOF
            return JUST_SNOW_BELOW;
    }

    // Check if santa is in a new street
    if (_pos.first < map.streets.front().get_address())
    {
        // Add new street to santa's map
        map.streets.push_front(Street(_pos));
        map.start++;
    }
    else if (_pos.first > map.streets.back().get_address())
    {
        // Add new street to santa's map
        map.streets.push_back(Street(_pos));
    }
    else
    {
        // Santa knows this street already
    }

    return HOUSE_BELOW;
}

void Santa::drop_present()
{
    // Enter the house below santa
    size_t street_addr = static_cast<size_t>(_pos.first + map.start);
    Street &current_street = map.streets.at(street_addr);
    House &house_below = current_street.enter_house(_pos);

    if (house_below.count_presents() == 0)
    {
        // First time visiting this house
        map.num_houses++;
    }

    // Drop a present
    house_below.add_present(1);
    _drop++;
}
