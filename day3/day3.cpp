#include "santa.h"

#include <fstream>
#include <iostream>
#include <list>

int main()
{
    std::ifstream file {"input"};
    Santa santa {};
    Santa robo_santa {};

    // Open file
    if (file.is_open() != true)
    {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    // Reconstruct santa's path
    while (file.eof() == false)
    {
        char dir_santa = static_cast<char>(file.get());
        char dir_robo = static_cast<char>(file.get());

        if (santa.move(dir_santa) == Santa::HOUSE_BELOW)
        {
            // A house has been found, quick before they hear santa!
            santa.drop_present();
        }

        if (robo_santa.move(dir_robo) == Santa::HOUSE_BELOW)
        {
            // A house has been found, quick before they hear santa!
            robo_santa.drop_present();
        }
    }

    // How's the night been?
    std::cout << santa.get_number_visited_houses()
              << " houses have at least one present\n";

    return 0;
}
