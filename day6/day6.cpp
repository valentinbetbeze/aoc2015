#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#define GRID_SIZE 1000U


/* Private Typedef ************************************************************/
typedef std::array<std::array<int, GRID_SIZE>, GRID_SIZE> Grid;


/* Private classes ************************************************************/
struct Pos
{
    size_t x;
    size_t y;
};

class Instruction
{
public:
    Instruction(Pos start, Pos end) : _s_pos {start}, _e_pos {end} {}
    virtual ~Instruction() = default;

    virtual void cmd(Grid &grid) = 0;

protected:
    Pos _s_pos;
    Pos _e_pos;
};

class TurnOff : public Instruction
{
public:
    TurnOff(Pos start, Pos end) : Instruction(start, end) {};

    void cmd(Grid &grid) override
    {
        for (auto x = _s_pos.x; x <= _e_pos.x; x++)
        {
            for (auto y = _s_pos.y; y <= _e_pos.y; y++)
            {
                auto &light = grid.at(x).at(y);
                if (light > 0)
                {
                    light -= 1;
                }
            }
        }
    }
};

class TurnOn : public Instruction
{
public:
    TurnOn(Pos start, Pos end) : Instruction(start, end) {};

    void cmd(Grid &grid) override
    {
        for (auto x = _s_pos.x; x <= _e_pos.x; x++)
        {
            for (auto y = _s_pos.y; y <= _e_pos.y; y++)
            {
                grid.at(x).at(y) += 1;
            }
        }
    }
};

class Toggle : public Instruction
{
public:
    Toggle(Pos start, Pos end) : Instruction(start, end) {};

    void cmd(Grid &grid) override
    {
        for (auto x = _s_pos.x; x <= _e_pos.x; x++)
        {
            for (auto y = _s_pos.y; y <= _e_pos.y; y++)
            {
                grid.at(x).at(y) += 2;
            }
        }
    }
};


/* Private Function Declarations **********************************************/
static std::unique_ptr<Instruction> parse_instruction(const std::string &in);
static void parse_position(const std::string &in, Pos &out);
static int count_lit(Grid &grid);


/* Public Function Definitions ************************************************/
int main()
{
    std::ifstream file {"input"};
    std::string line {};
    Grid grid {};

    if (not file.is_open())
    {
        std::cerr << "Failed to open input file\n";
        return 1;
    }

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            break;
        }
        // Parse raw instruction
        auto instruction = parse_instruction(line);
        // Follow Santa's instruction
        instruction->cmd(grid);
    }

    std::cout << "The total brightness of all lights combined is "
              << count_lit(grid) << "\n";

    return 0;
}


/* Private Function Definitions ***********************************************/
static std::unique_ptr<Instruction> parse_instruction(const std::string &in)
{
    std::istringstream raw {in};
    std::vector<std::string> tokens {};
    std::string tok {};
    std::unique_ptr<Instruction> instruction = nullptr;
    Pos start {};
    Pos end {};

    while (raw >> tok)
    {
        if (tok != "through")
        {
            tokens.push_back(tok);
        }
    }

    // Parse ending position
    parse_position(tokens.back(), end);
    tokens.pop_back();

    // Parse starting position
    parse_position(tokens.back(), start);
    tokens.pop_back();

    // Parse command
    if (tokens.back() == "off")
    {
        instruction = std::make_unique<TurnOff>(start, end);
    }
    else if (tokens.back() == "on")
    {
        instruction = std::make_unique<TurnOn>(start, end);
    }
    else
    {
        instruction = std::make_unique<Toggle>(start, end);
    }

    return instruction;
}

static void parse_position(const std::string &in, Pos &out)
{
    auto idx = in.find(',');
    out.x = static_cast<size_t>(std::stoi(in.substr(0, idx)));
    out.y = static_cast<size_t>(std::stoi(in.substr(idx + 1, in.size())));
}

static int count_lit(Grid &grid)
{
    int count = 0;

    for (auto row : grid)
    {
        for (auto light : row)
        {
            count += light;
        }
    }

    return count;
}
