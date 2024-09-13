#include "helper.h"

#include <fstream>
#include <iostream>

int parse_file(const std::string &file_name, std::vector<std::string> &lines)
{
    std::ifstream file {file_name};
    std::string l {};

    if (not file.is_open())
    {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    while (std::getline(file, l))
    {
        if (not l.empty())
        {
            lines.push_back(l);
        }
    }

    return 0;
}
