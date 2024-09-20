#include <fstream>
#include <iostream>

int main()
{
    auto floor = 0;
    auto has_entered_basement = false;
    std::ifstream file;

    // Open file
    file.open("input");
    if (file.is_open() != true)
    {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    // Part 1: find which floor Santa should take given the input instructions
    while (file.eof() == false)
    {
        switch (static_cast<char>(file.get()))
        {
            case '(':
                floor++;
                break;
            case ')':
                floor--;
                break;
            default:
                break;
        }

        /* Part 2: find the position of the first instruction which leads Santa
        to enter the basement */
        if ((floor < 0) && (has_entered_basement == false))
        {
            std::cout << "Santa first enters the basement at position "
                      << file.tellg() << '\n';
            has_entered_basement = true;
        }
    }

    std::cout << "The instruction takes Santa to floor " << floor << std::endl;

    return 0;
}
