#include "helper.h"

#include <fstream>
#include <iostream>

void parse_file(const std::string &file_name, std::vector<std::string> &lines)
{
    std::ifstream file {file_name};
    std::string l {};

    if (not file.is_open())
    {
        throw std::ios_base::failure {"Failed to open file " + file_name};
    }

    while (std::getline(file, l))
    {
        if (not l.empty())
        {
            lines.push_back(l);
        }
    }

    file.close();
}
