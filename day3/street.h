#include <deque>

#ifndef _STREET_H_
#define _STREET_H_


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
     * @brief
     *
     * @param p
     * @return House&
     */
    House &enter_house(const Pos p);

private:
    std::deque<House> _houses;
    const int _address = 0;
};


#endif    // _STREET_H_
