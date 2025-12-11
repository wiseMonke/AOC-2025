#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../utils/timer.hpp"

int main()
{
    Timer t("Day 11, Part 1");
    std::ifstream file("input.txt");
    std::string line;

    std::unordered_map<std::string, std::vector<std::string>> graph;
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

    std::vector<std::string> stack = {"you"};
    std::unordered_map<std::string, bool> visited;
    long long pathCount = 0;

    while (!stack.empty())
    {
        std::string current = stack.back();
        stack.pop_back();

        if (current == "out")
        {
            pathCount++;
            continue;
        }

        visited[current] = true;
        for (const auto &neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                stack.push_back(neighbor);
            }
        }

        visited[current] = false;
    }

    std::cout << "Total: " << pathCount << "\n";
    return 0;
}