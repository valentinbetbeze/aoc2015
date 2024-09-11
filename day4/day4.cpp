// https://terminalroot.com/how-to-generate-md5-hash-with-cpp-and-openssl/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <openssl/md5.h>
#include <sstream>
#include <string>

#define LEADING_ZEROES 6

static std::string build_hash(std::string &data);

int main()
{
    std::ifstream file {"input"};
    std::string input {};
    std::string hash {};
    int answer = -1;

    MD5_CTX ctx {};
    MD5_Init(&ctx);

    // Get input key from input file
    if (file.is_open())
    {
        std::getline(file, input);
        file.close();
    }
    else
    {
        std::cerr << "Error: failed to open file\n";
        return 1;
    }

    // Find the lowest positive number to get a target hash
    do
    {
        answer++;
        // Build data
        std::string data = input + std::to_string(answer);
        // Build MD5 hash of data
        hash = build_hash(data);

    } while (hash.find_first_not_of('0') < LEADING_ZEROES);

    std::cout << "The answer is " << answer << '\n';

    return 0;
}

static std::string build_hash(std::string &data)
{
    std::stringstream s_hash {};
    unsigned char hash[MD5_DIGEST_LENGTH] {};

    MD5((const unsigned char *)data.c_str(), data.length(), hash);

    // Concatenate hash into string stream
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        s_hash << std::hex << std::setw(2) << std::setfill('0')
               << static_cast<int>(hash[i]);
    }

    return s_hash.str();
}
