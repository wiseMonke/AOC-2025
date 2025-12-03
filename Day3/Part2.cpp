#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../utils/timer.hpp"

#define N_SIZE 12

std::string max12DigitNumber(const std::string &s, const int n)
{
    int length = s.size();
    int toRemove = length - n;
    std::string stack;

    for (const char &c : s)
    {
        while (!stack.empty() && toRemove > 0 && stack.back() < c)
        {
            stack.pop_back();
            toRemove--;
        }
        stack.push_back(c);
    }

    stack.resize(n);
    return stack;
}

int main()
{
    Timer t("Day 3, Part 2");
    std::ifstream inputFile("input.txt");
    std::string line;
    long long int total = 0;

    while (std::getline(inputFile, line))
    {
        int size = line.size();
        total += std::stoull(max12DigitNumber(line, N_SIZE));
    }

    std::cout << "Total: " << total << "\n";
    return 0;
}
