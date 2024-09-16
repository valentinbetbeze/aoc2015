#include <fstream>
#include <iostream>
#include <set>
#include <string>

using Coords = std::pair<int, int>;

void update_coords(Coords &cur, const char dir);

int main()
{
    std::ifstream file {"../input"};

    std::set<Coords> houses {};
    Coords santa_coord {0, 0};
    Coords robo_coord {0, 0};

    if (not file.is_open())
    {
        std::cerr << "Failed to open input file\n";
        return 1;
    }

    // Drop a present at santa's location
    houses.insert(santa_coord);

    // Reconstruct santa's path
    while (not file.eof())
    {
        // Part 1
        update_coords(santa_coord, static_cast<char>(file.get()));
        houses.insert(santa_coord);
        // Part 2
        update_coords(robo_coord, static_cast<char>(file.get()));
        houses.insert(robo_coord);
    }

    // How's the night been?
    std::cout << houses.size() << " houses have at least one present\n";

    return 0;
}

void update_coords(Coords &coord, const char dir)
{
    switch (dir)
    {
        case '>':
            coord.first++;
            break;
        case '<':
            coord.first--;
            break;
        case '^':
            coord.second++;
            break;
        case 'v':
            coord.second--;
            break;
        default:
            // Wrong input, or \n, or EOF
            break;
    }
}
