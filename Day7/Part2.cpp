#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 7, Part 2");
    std::ifstream file("input.txt");
    std::vector<std::string> grid;
    std::string line;

    while (std::getline(file, line))
    {
        grid.push_back(line);
    }

    size_t H = grid.size();
    size_t W = grid[0].size();
    size_t indexS = 0;

    for (size_t j = 0; j < W; ++j)
    {
        if (grid[0][j] == 'S')
        {
            indexS = j;
            break;
        }
    }

    std::vector<long long> beams(W, 0);
    beams[indexS] = 1;

    for (size_t i = 0; i < H; ++i)
    {
        std::vector<long long> nextBeams(W, 0);
        for (size_t j = 0; j < W; ++j)
        {
            if (grid[i][j] == '^')
            {
                if (j > 0)
                    nextBeams[j - 1] += beams[j];
                if (j + 1 < W)
                    nextBeams[j + 1] += beams[j];
            }
            else
            {
                nextBeams[j] += beams[j];
            }
        }
        beams = std::move(nextBeams);
    }

    long long total = std::accumulate(beams.begin(), beams.end(), 0LL);
    std::cout << "Total: " << total << "\n";
    return 0;
}