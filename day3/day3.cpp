#include "santa.h"

#include <fstream>
#include <iostream>
#include <list>

int main()
{
    std::ifstream file {"input"};
    Santa santa {};

    // Open file
    if (file.is_open() != true)
    {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    // Reconstruct santa's path
    while (file.eof() == false)
    {
        char dir = static_cast<char>(file.get());

        if (santa.move(dir) == Santa::HOUSE_BELOW)
        {
            // A house has been found, quick before they hear santa!
            santa.drop_present();
        }
    }

    // How's the night been?
    std::cout << santa.get_num_houses()
              << " houses have at least one present\n";

    return 0;
}
