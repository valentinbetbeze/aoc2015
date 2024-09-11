#include "street.h"

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

    Santa() : _pos {0, 0}, _streets {Street()}
    {
        // Santa is generous: he drops a present as soon as he arrives
        drop_present();
    }

    /**
     * @brief
     *
     * @param dir
     * @return Below
     */
    Below move(const char dir);
    /**
     * @brief Drop a present at santa's location
     *
     */
    void drop_present();
    /**
     * @brief Return the number of unique houses santa has visited
     *
     */
    int get_num_houses() const
    {
        return _num_houses;
    }

private:
    Pos _pos;
    int _drop = 0;
    int _num_houses = 0;

    // Santa always keeps a map of the town with him
    std::deque<Street> _streets;
    int _base_idx = 0;
};


#endif    // _SANTA_H_
