#include <iostream>
#include <fstream>
#include <string>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 1, Part 1");
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream file("input.txt");
    std::string line;
    int position = 50, counter = 0;

    while (std::getline(file, line))
    {
        int n = 0;
        for (size_t i = 1; i < line.size(); ++i)
        {
            n = n * 10 + (line[i] - '0');
        }

        if (line[0] == 'L')
            position -= n;
        else
            position += n;

        position %= 100;
        if (position < 0)
            position += 100;
        if (position == 0)
            counter++;
    }

    std::cout << counter << '\n';
    return 0;
}
