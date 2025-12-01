#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 1, Part 2");
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream file("input.txt");
    std::string line;

    int counter = 0;
    int position = 50;

    while (std::getline(file, line))
    {
        char direction = line[0];

        int n = 0;
        for (size_t i = 1; i < line.size(); ++i)
        {
            n = n * 10 + (line[i] - '0');
        }

        if (direction == 'R')
        {
            int stepsNeeded = (100 - position) % 100;
            if (stepsNeeded == 0)
                stepsNeeded = 100;

            if (n >= stepsNeeded)
            {
                counter += 1 + (n - stepsNeeded) / 100;
            }

            position += n;
            position %= 100;
        }
        else
        {
            int stepsNeeded = position;
            if (stepsNeeded == 0)
                stepsNeeded = 100;

            if (n >= stepsNeeded)
            {
                counter += 1 + (n - stepsNeeded) / 100;
            }

            position -= n;
            position %= 100;
            if (position < 0)
                position += 100;
        }
    }

    std::cout << counter << '\n';
    return 0;
}