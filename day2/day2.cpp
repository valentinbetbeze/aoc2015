#include "helper.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

class Present
{
public:
    Present(const int l = 0, const int w = 0, const int h = 0) :
        dimensions {l, w, h}
    {
        // sort dimensions by ascending size
        std::sort(dimensions.begin(), dimensions.end());
    }

    int compute_required_wrapping_paper() const
    {
        return (2 * (dimensions.at(0) * dimensions.at(1) +
                     dimensions.at(1) * dimensions.at(2) +
                     dimensions.at(2) * dimensions.at(0))) +
               dimensions.at(0) * dimensions.at(1);
    }
    int compute_required_ribbon() const
    {
        return (dimensions.at(0) * dimensions.at(1) * dimensions.at(2)) +
               (2 * (dimensions.at(0) + dimensions.at(1)));
    }

private:
    std::array<int, 3> dimensions {};
};

int main()
{
    std::vector<std::string> lines {};
    int wrapping = 0;
    int ribbon = 0;

    parse_file("input", lines);

    // Go through every present in the file, one by one
    for (const auto &l : lines)
    {
        // Parse the dimension of the present
        size_t i_fst = l.find_first_of('x');
        size_t i_snd = l.find_last_of('x');

        Present present {
            std::stoi(l.substr(0, i_fst)),
            std::stoi(l.substr(i_fst + 1, i_snd - (i_fst + 1))),
            std::stoi(l.substr(i_snd + 1, l.size() - (i_snd + 1))),
        };

        // Compute the required wrapping paper surface & ribbon length
        wrapping += present.compute_required_wrapping_paper();
        ribbon += present.compute_required_ribbon();
    }

    std::cout << "The elves should order " << wrapping
              << " square feet of wrapping paper\n";
    std::cout << "The elves should order " << ribbon
              << " feet of wrapping paper\n";
    return 0;
}
