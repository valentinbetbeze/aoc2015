#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define NUM_PAIR_MIN 2

static bool is_nice(const std::string &str);

int main()
{
    std::ifstream file {"input"};
    std::string string {};
    int num_nice_strings = 0;

    if (not file.is_open())
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
 *          * contains a consecutive pair of letters at least twice without
 *            overlapping
 *          * contains at least one letter which repeat with one letter in
 *            between
 *
 * @param str String to parse
 * @return true The string is nice
 * @return false The string is naughty
 */
static bool is_nice(const std::string &str)
{
    bool pair_found = false;
    bool mirror_found = false;
    std::vector<std::string> pairs {};
    std::vector<std::string> triples {};
    constexpr int pair_len = 2;
    constexpr int triple_len = 3;

    for (size_t i = 0; i < str.length(); i++)
    {
        auto p = str.substr(i, pair_len);
        auto t = str.substr(i, triple_len);

        if (p.length() == pair_len)
        {
            pairs.push_back(p);
        }
        if (t.length() == triple_len)
        {
            triples.push_back(t);
        }
    }

    // Check non-overlapping pairs
    for (auto ref_chunk = pairs.begin(); ref_chunk != pairs.end(); ++ref_chunk)
    {
        // Find a pair
        for (auto chunk = (ref_chunk + 1); chunk != pairs.end(); ++chunk)
        {
            bool chunks_match = not((*chunk).compare(*ref_chunk));
            bool chunks_adjacent = (chunk == (ref_chunk + 1));

            if (chunks_match and not chunks_adjacent)
            {
                pair_found = true;
                break;
            }
        }
    }

    // Check mirrors
    for (auto t : triples)
    {
        if (t.front() == t.back())
        {
            mirror_found = true;
        }
    }

    if (pair_found and mirror_found)
    {
        return true;
    }
    else
    {
        return false;
    }
}
