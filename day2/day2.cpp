#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>

#define PRESENT_DIM_NUMBER           3
#define PRESENT_DIM_SEPARATOR        'x'
#define PRESENT_GET_SURFACE(l, w, h) (2 * (l * w + w * h + h * l))
#define PRESENT_GET_VOLUME(l, w, h)  (l * w * h)
#define RIBBON_GET_LEN(a, b)         (2 * a + 2 * b)

int main()
{
    std::ifstream file {"input"};
    std::string raw;
    auto paper_size = 0;
    auto ribbon_len = 0;

    if (file.is_open() != true)
    {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    // Go through every present in the file, one by one
    while (std::getline(file, raw))
    {
        // Parse the dimension of the present
        std::array<int, PRESENT_DIM_NUMBER> dim {};
        size_t i_fst = raw.find_first_of(PRESENT_DIM_SEPARATOR);
        size_t i_snd = raw.find_last_of(PRESENT_DIM_SEPARATOR);

        dim.at(0) = std::stoi(raw.substr(0, i_fst));
        dim.at(1) = std::stoi(raw.substr(i_fst + 1, i_snd - (i_fst + 1)));
        dim.at(2) = std::stoi(raw.substr(i_snd + 1, raw.size() - (i_snd + 1)));

        // Sort dimension to easily get the smallest surface
        std::sort(dim.begin(), dim.end());

        // Compute the required wrapping paper surface & ribbon length
        paper_size += PRESENT_GET_SURFACE(dim.at(0), dim.at(1), dim.at(2)) +
                      dim.at(0) * dim.at(1);
        ribbon_len += RIBBON_GET_LEN(dim.at(0), dim.at(1)) +
                      PRESENT_GET_VOLUME(dim.at(0), dim.at(1), dim.at(2));
    }

    std::cout << "The elves should order " << paper_size
              << " square feet of wrapping paper\n";
    std::cout << "The elves should order " << ribbon_len
              << " feet of wrapping paper\n";
    return 0;
}
