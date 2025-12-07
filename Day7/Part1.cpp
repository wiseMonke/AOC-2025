#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 7, Part 1");
    std::ifstream file("input.txt");
    std::string line;

    std::vector<std::string> grid;
    while (std::getline(file, line))
    {
        grid.push_back(line);
    }

    long long count = 0;
    size_t rows = grid.size();
    size_t cols = grid[0].size();

    for (size_t j = 0; j < cols; j++)
    {
        if (grid[0][j] == 'S')
        {
            grid[0][j] = '|';
            break;
        }
    }

    for (size_t i = 1; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (grid[i][j] == '.' && grid[i - 1][j] == '|')
            {
                grid[i][j] = '|';
            }
            else if (grid[i][j] == '^' && grid[i - 1][j] == '|')
            {
                count++;
                if (j > 0)
                    grid[i][j - 1] = '|';
                if (j < cols)
                    grid[i][j + 1] = '|';
            }
        }
    }

    std::cout << "Total: " << count << "\n";
    return 0;
}