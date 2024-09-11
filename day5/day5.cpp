#include <array>
#include <fstream>
#include <iostream>
#include <string>

#define NUM_VOWELS_MIN 3

static bool is_nice(const std::string &str);

int main()
{
    std::ifstream file {"input"};
    std::string string {};
    int num_nice_strings = 0;

    if (file.is_open() == false)
    {
        std::cerr << "Failed to open input file\n";
        return 1;
    }

    while (std::getline(file, string))
    {
        if (is_nice(string))
        {
            num_nice_strings++;
        }        
    }

    std::cout << "Santa has " << num_nice_strings << " nice strings\n";

    return 0;
}

/**
 * @brief To be nice, a string must:
 *          * contain at least 3 vowels (aeiou)
 *          * contain at least 1 succession of two letters in a row
 *          * not contain the following substrings: "ab", "cd", "pq", or "xy"
 *
 * @param str String to parse
 * @return true The string is nice
 * @return false The string is naughty
 */
static bool is_nice(const std::string &str)
{
    int num_vowels = 0;
    bool has_succession = false;
    bool has_substring = false;
    const std::string vowels {"aeiou"};
    const std::array<std::string, 4> substr {"ab", "cd", "pq", "xy"};

    for (auto it = str.begin(); it != str.end(); it++)
    {
        auto c = *it;

        // Check if vowel
        if (vowels.find(c) != vowels.npos)
        {
            num_vowels++;
        }

        if (it > str.begin())
        {
            auto previous_c = it[-1];
            // Check succession
            if (previous_c == c)
            {
                has_succession = true;
            }
            // Check substrings
            std::string chunck {previous_c, c};
            for (auto s : substr)
            {
                if (s.compare(chunck) == 0)
                {
                    has_substring = true;
                }
            }
        }
    }

    if ((num_vowels >= NUM_VOWELS_MIN) && has_succession &&
        (has_substring == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}
