#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 2, Part 2");
    std::ifstream file("input.txt");
    std::string line;
    std::getline(file, line);

    uint64_t total = 0;
    size_t position = 0;

    while (position < line.size())
    {
        size_t nextComma = line.find(',', position);
        if (nextComma == std::string::npos)
            nextComma = line.size();

        std::string token = line.substr(position, nextComma - position);
        size_t dash = token.find('-');
        if (dash != std::string::npos)
        {
            uint64_t start = std::stoull(token.substr(0, dash));
            uint64_t end = std::stoull(token.substr(dash + 1));

            for (uint64_t x = start; x <= end; ++x)
            {
                if (x < 10)
                    continue;
                else if (x <= 99)
                {
                    if (x % 11 == 0)
                        total += x;
                }
                else if (x <= 999)
                {
                    if (x % 111 == 0)
                        total += x;
                }
                else if (x <= 9999)
                {
                    if (x % 101 == 0 || x % 1111 == 0)
                        total += x;
                }
                else if (x <= 99999)
                {
                    if (x % 11111 == 0)
                        total += x;
                }
                else if (x <= 999999)
                {
                    if (x % 1001 == 0 || x % 10101 == 0 || x % 111111 == 0)
                        total += x;
                }
                else if (x <= 9999999)
                {
                    if (x % 1111111 == 0)
                        total += x;
                }
                else if (x <= 99999999)
                {
                    if (x % 10001 == 0 || x % 1010101 == 0 || x % 11111111 == 0)
                        total += x;
                }
                else if (x <= 999999999ULL)
                {
                    if (x % 1001001 == 0 || x % 111111111 == 0)
                        total += x;
                }
                else if (x <= 9999999999ULL)
                {
                    if (x % 100001 == 0 || x % 101010101 == 0 || x % 1111111111ULL == 0)
                        total += x;
                }
            }
        }
        position = nextComma + 1;
    }

    std::cout << "Day 2, Part 2: " << total << '\n';
    return 0;
}