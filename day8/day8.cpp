#include "helper.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> input {};
    std::ofstream output {"output.cpp"};

    if (parse_file("input", input))
    {
        return 1;
    }

    if (not output.is_open())
    {
        std::cerr << "Failed to create output.cpp\n";
        return 1;
    }

    output << "#include \"helper.h\"\n"
              "\n"
              "#include <array>\n"
              "#include <iostream>\n"
              "#include <string>\n"
              "#include <vector>\n"
              "\n"
              "const std::array<std::string, "
           << input.size() << "> list {\n";

    for (auto &line : input)
    {
        // Add 2 double quote to ensure hex format is recognized by compiler
        size_t idx_x = 0;
        do
        {
            idx_x = line.find("\\x", idx_x);
            if (idx_x != line.npos)
            {
                line.replace(idx_x + 4, 0, "\"\"");
            }
        } while (idx_x++ != line.npos);

        output << "\t" << line << ",\n";
    }

    output << "};\n\n";

    output << "int main()\n \
{\n \
    std::vector<std::string> input {};\n \
    size_t diff = 0;\n \
    \n \
    if (parse_file(\"input\", input))\n \
    {\n \
        return 1;\n \
    }\n \
    \n \
    for (size_t idx = 0; idx < input.size(); ++idx)\n \
    {\n \
        const auto &str_code = input.at(idx);\n \
        const auto &str_mem = list.at(idx);\n \
        \n \
        diff += str_code.length() - str_mem.length();\n \
    }\n \
    \n \
    std::cout << \"Result: \" << diff << '\\n';\n \
    \n \
    return 0;\n \
}\n";

    output.close();

    if (system("make TARGET=output") == -1)
    {
        std::cerr << "Failed to compile output.cpp\n";
        return 1;
    }

    if (system("./output") == -1)
    {
        std::cerr << "Failed to execute output\n";
        return 1;
    }

    return 0;
}
