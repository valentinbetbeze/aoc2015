#include "santa.h"

#include <iostream>


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
    if (_pos.first < _streets.front().get_address())
    {
        // Add new street to santa's map
        _streets.push_front(Street(_pos));
        _base_idx++;
    }
    else if (_pos.first > _streets.back().get_address())
    {
        // Add new street to santa's map
        _streets.push_back(Street(_pos));
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
    size_t deque_idx = static_cast<size_t>(_pos.first + _base_idx);
    Street &current_street = _streets.at(deque_idx);
    House &house_below = current_street.enter_house(_pos);

    if (house_below.count_presents() == 0)
    {
        // First time visiting this house
        _num_houses++;
    }

    // Drop a present
    house_below.add_present(1);
    _drop++;
}
