#include "house.h"

#include <deque>

#ifndef _STREET_H_
#define _STREET_H_


/**
 * @brief A street is a collection of houses
 *
 */
class Street
{
public:
    Street() : _houses {House()} {};
    Street(Pos p) : _houses {House(p)}, _address {p.first} {}

    int get_address() const
    {
        return _address;
    }
    /**
     * @brief Get the house object at the given @p p location or create it and
     * add it to the street map @p _houses
     *
     * @param p Location of the house to enter
     * @return House&
     */
    House &enter_house(const Pos p);

private:
    std::deque<House> _houses;
    const int _address = 0;
};


#endif    // _STREET_H_
