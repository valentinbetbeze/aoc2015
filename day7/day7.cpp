#include "helper.h"

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>


struct Wire
{
    int signal = -1;
    std::string id {};
    std::string input1 {};
    std::string input2 {};
    std::string gate {};
};


using Circuit = std::unordered_map<std::string, Wire>;


static void parse_instruction(const std::string &instruction, Wire &wire);
static Wire &get_wire(Circuit &circuit, const std::string &wire_id);
static int solve_circuit(Circuit &circuit, const std::string &wire_id);
static void reset_circuit(Circuit &circuit);


int main()
{
    std::vector<std::string> input {};
    Circuit circuit {};

    parse_file("input", input);

    // Create the circuit
    for (const auto &instruction : input)
    {
        // Create the wire from the instruction
        Wire wire {};
        parse_instruction(instruction, wire);
        // Add the wire to the circuit
        circuit.insert(std::make_pair(wire.id, wire));
    }

    /* Part 1: Solve the circuit for a given wire */
    const std::string wire_part_1 {"a"};
    auto signal_part_1 = solve_circuit(circuit, wire_part_1);
    // Print the signal value
    std::cout << "Part 1: Wire \'" << wire_part_1 << "\' is given the signal "
              << signal_part_1 << '\n';

    /* Part 2: Override wire b to the signal */
    reset_circuit(circuit);
    auto &wire_part_2 = get_wire(circuit, "b");
    wire_part_2.signal = signal_part_1;
    // Resolve the circuit and print the new signal of wire 'a'
    std::cout << "Part 2: Wire \'" << wire_part_1 << "\' is given the signal "
              << solve_circuit(circuit, wire_part_1) << '\n';

    return 0;
}


static void parse_instruction(const std::string &instruction, Wire &wire)
{
    std::istringstream ss {instruction};
    std::string tok {};
    bool lvalue = false;

    while (ss >> tok)
    {
        if (lvalue)
        {
            wire.id = tok;
        }
        else if (tok == "->")
        {
            lvalue = true;
        }
        else
        {
            const auto c = tok.front();
            if (islower(c) || isdigit(c))
            {
                if (wire.input1.empty())
                {
                    wire.input1 = tok;
                }
                else
                {
                    wire.input2 = tok;
                }
            }
            else
            {
                if (isupper(c))
                {
                    wire.gate = tok;
                }
            }
        }
    }
}

static Wire &get_wire(Circuit &circuit, const std::string &wire_id)
{
    auto it = circuit.find(wire_id);
    if (it == circuit.end())
    {
        throw std::logic_error("Failed to get wire id" + wire_id);
    }

    return it->second;
}

static int solve_circuit(Circuit &circuit, const std::string &wire_id)
{
    // Get target wire
    Wire &wire = get_wire(circuit, wire_id);

    // Check if wire has already been solved
    if (wire.signal != -1)
    {
        return wire.signal;
    }

    auto &op1 = wire.input1;
    auto &op2 = wire.input2;
    int input_signal_1 = 0;
    int input_signal_2 = 0;

    // Solve the first operand signal
    if (not op1.empty())
    {
        if (isdigit(op1.front()))
        {
            // First operand is a constant
            input_signal_1 = std::stoi(op1);
        }
        else
        {
            // First operand is a wire
            input_signal_1 = solve_circuit(circuit, op1);
        }
    }

    // Solve the second operand signal
    if (not op2.empty())
    {
        if (isdigit(op2.front()))
        {
            // First operand is a constant
            input_signal_2 = std::stoi(op2);
        }
        else
        {
            // First operand is a wire
            input_signal_2 = solve_circuit(circuit, op2);
        }
    }

    // Solve the wire signal
    if (wire.gate.empty() or wire.gate == "OR")
    {
        wire.signal = static_cast<std::uint16_t>(input_signal_1 |
                                                 input_signal_2);
    }
    else if (wire.gate == "NOT")
    {
        wire.signal = static_cast<std::uint16_t>(
            ~(input_signal_1 | input_signal_2));
    }
    else if (wire.gate == "AND")
    {
        wire.signal = static_cast<std::uint16_t>(input_signal_1 &
                                                 input_signal_2);
    }
    else if (wire.gate == "LSHIFT")
    {
        wire.signal = static_cast<std::uint16_t>(input_signal_1
                                                 << input_signal_2);
    }
    else if (wire.gate == "RSHIFT")
    {
        wire.signal = static_cast<std::uint16_t>(input_signal_1 >>
                                                 input_signal_2);
    }
    else
    {
        std::cerr << "Error: Unknown gate mnemonics\n";
    }

    return wire.signal;
}

static void reset_circuit(Circuit &circuit)
{
    for (auto &wire : circuit)
    {
        wire.second.signal = -1;
    }
}
