#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../utils/timer.hpp"

int maxValueFromString(const std::string &str)
{
    int maxFirst = str[0] - '0';
    int best = 0;
    for (size_t i = 1; i < str.size(); ++i)
    {
        int second = str[i] - '0';
        best = std::max(best, maxFirst * 10 + second);
        maxFirst = std::max(maxFirst, second);
    }
    return best;
}

int main()
{
    Timer t("Day 3, Part 1");
    std::ifstream inputFile("input.txt");
    std::string line;
    int total = 0;

    while (std::getline(inputFile, line))
    {
        total += maxValueFromString(line);
    }

    std::cout << "Total: " << total << "\n";
    return 0;
}