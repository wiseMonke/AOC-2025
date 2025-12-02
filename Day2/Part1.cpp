#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdint>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 2, Part 1");
    std::ifstream file("input.txt");
    std::string line;
    std::getline(file, line);

    std::vector<std::pair<uint64_t, uint64_t>> ranges;
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
            uint64_t a = std::stoull(token.substr(0, dash));
            uint64_t b = std::stoull(token.substr(dash + 1));
            ranges.emplace_back(a, b);
        }
        position = nextComma + 1;
    }

    uint64_t total = 0;
    for (auto [start, end] : ranges)
    {
        for (uint64_t x = start; x <= end; ++x)
        {
            if (x >= 10 && x <= 99)
            {
                if (x % 11 == 0)
                    total += x;
            }
            else if (x >= 1000 && x <= 9999)
            {
                if (x % 101 == 0)
                    total += x;
            }
            else if (x >= 100000 && x <= 999999)
            {
                if (x % 1001 == 0)
                    total += x;
            }
            else if (x >= 10000000 && x <= 99999999)
            {
                if (x % 10001 == 0)
                    total += x;
            }
            else if (x >= 1000000000ULL && x <= 9999999999ULL)
            {
                if (x % 100001 == 0)
                    total += x;
            }
        }
    }

    std::cout << "Day 2, Part 1: " << total << '\n';
    return 0;
}