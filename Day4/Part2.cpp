#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../utils/timer.hpp"

int countNeighbours(const std::vector<std::string> &grid, int x, int y)
{
    int count = 0;
    const int directions[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (const auto &dir : directions)
    {
        int newX = x + dir[0];
        int newY = y + dir[1];
        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size())
        {
            if (grid[newX][newY] == '@')
            {
                count++;
            }
        }
    }
    return count;
}

int solve(std::vector<std::string> &grid)
{
    std::vector<std::pair<int, int>> indexList;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (grid[i][j] == '@' && countNeighbours(grid, i, j) < 4)
            {
                indexList.emplace_back(i, j);
            }
        }
    }

    for (const auto &[x, y] : indexList)
    {
        grid[x][y] = '.';
    }

    return indexList.size();
}

int main()
{
    Timer t("Day 4, Part 2");
    std::ifstream file("input.txt");
    std::string line;

    std::vector<std::string> lines;
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    int counter = 0;
    while (true)
    {
        int result = solve(lines);
        if (result == 0)
        {
            break;
        }
        counter += result;
    }

    std::cout << "Total: " << counter << "\n";
    return 0;
}