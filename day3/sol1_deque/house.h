#include <utility>

#ifndef _HOUSE_H_
#define _HOUSE_H_

/**
 * @brief 2D position (first: x, second: y)
 *
 */
typedef std::pair<int, int> Pos;


class House
{
public:
    House(Pos p = {0, 0}) : _pos {p} {}

    const Pos &get_pos() const
    {
        return _pos;
    }
    int count_presents() const
    {
        return _presents;
    }
    void add_present(int n)
    {
        _presents += n;
    }

private:
    const Pos _pos;
    int _presents = 0;
};


#endif    // _HOUSE_H
