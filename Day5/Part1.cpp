#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 5, Part 1");
    std::ifstream file("input.txt");
    std::string line;

    std::vector<std::pair<long long int, long long int>> ranges;
    std::vector<std::pair<long long int, long long int>> mergedRanges;

    bool endOfRanges = false;
    int counter = 0;
    while (std::getline(file, line))
    {
        if (line.empty())
        {
            endOfRanges = true;
            std::sort(ranges.begin(), ranges.end());

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

            continue;
        }

        if (!endOfRanges)
        {
            size_t position = line.find('-');
            long long int start = std::stoull(line.substr(0, position));
            long long int end = std::stoull(line.substr(position + 1));
            ranges.emplace_back(start, end);
        }
        else
        {
            long long int number = std::stoull(line);
            auto it = std::lower_bound(mergedRanges.begin(), mergedRanges.end(),
                                       std::make_pair(number, LLONG_MIN));

            bool inRange = false;
            if (it != mergedRanges.end() && number >= it->first && number <= it->second)
            {
                inRange = true;
            }
            else if (it != mergedRanges.begin())
            {
                it--;
                if (number >= it->first && number <= it->second)
                {
                    inRange = true;
                }
            }

            if (inRange)
            {
                counter++;
            }
        }
    }

    std::cout << "Total: " << counter << "\n";
    return 0;
}