#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include "../utils/timer.hpp"

std::unordered_map<std::string, std::vector<std::string>> graph;
std::unordered_map<std::string, std::array<long long, 4>> memo;

long long dfs(const std::string &node, bool hasFFT, bool hasDAC)
{
    if (node == "out")
    {
        return (hasFFT && hasDAC) ? 1LL : 0LL;
    }

    if (node == "fft")
        hasFFT = true;
    else if (node == "dac")
        hasDAC = true;

    int mask = (hasFFT ? 1 : 0) | (hasDAC ? 2 : 0);
    if (memo.find(node) == memo.end())
    {
        memo[node] = {-1LL, -1LL, -1LL, -1LL};
    }
    if (memo[node][mask] != -1)
    {
        return memo[node][mask];
    }

    long long count = 0;
    if (graph.count(node))
    {
        for (const auto &neighbor : graph[node])
        {
            count += dfs(neighbor, hasFFT, hasDAC);
        }
    }

    memo[node][mask] = count;
    return count;
}

int main()
{
    Timer t("Day 11, Part 2");
    std::ifstream file("input.txt");
    std::string line;

    while (std::getline(file, line))
    {
        std::vector<std::string> adjacents;
        std::string node = line.substr(0, line.find(": "));

        line = line.substr(line.find(": ") + 2);
        size_t pos = 0;
        while ((pos = line.find(" ")) != std::string::npos)
        {
            adjacents.push_back(line.substr(0, pos));
            line.erase(0, pos + 1);
        }
        if (!line.empty())
        {
            adjacents.push_back(line);
        }

        graph[node] = adjacents;
    }

    long long result = dfs("svr", false, false);
    std::cout << "Total: " << result << "\n";
    return 0;
}