#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 5, Part 2");
    std::ifstream file("input.txt");
    std::string line;

    std::vector<std::pair<long long int, long long int>> ranges;
    while (std::getline(file, line))
    {
        if (line.empty())
        {
            break;
        }

        size_t position = line.find('-');
        if (position == std::string::npos)
        {
            std::cerr << "Invalid line format: " << line << "\n";
            continue;
        }

        long long int start = std::stoll(line.substr(0, position));
        long long int end = std::stoll(line.substr(position + 1));
        ranges.emplace_back(start, end);
    }

    std::sort(ranges.begin(), ranges.end());
    std::vector<std::pair<long long int, long long int>> mergedRanges;

    for (const auto &range : ranges)
    {
        if (mergedRanges.empty() || range.first > mergedRanges.back().second + 1)
        {
            mergedRanges.push_back(range);
        }
        else
        {
            mergedRanges.back().second = std::max(mergedRanges.back().second, range.second);
        }
    }

    long long total = 0;
    for (const auto &range : mergedRanges)
    {
        total += (range.second - range.first + 1);
    }

    std::cout << "Total: " << total << "\n";
    return 0;
}