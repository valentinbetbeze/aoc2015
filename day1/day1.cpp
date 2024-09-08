#include <fstream>
#include <iomanip>
#include <iostream>

int main()
{
    auto floor = 0;
    std::ifstream file;

    // Open file
    file.open("input");
    if (file.is_open() != true)
    {
        std::cout << "Failed to open file\n";
        return 1;
    }

    // Part 1: find which floor Santa should take given the input instructions
    while (file.eof() == false)
    {
        auto ch = file.get();

        if (static_cast<char>(ch) == '(')
        {
            floor++;
        }
        else
        {
            if (static_cast<char>(ch) == ')')
            {
                floor--;
            }
        }
    }
    std::cout << "The instruction takes Santa to floor " << floor << std::endl;

    return 0;
}
