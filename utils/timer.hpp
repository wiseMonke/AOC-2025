// utils/timer.hpp
#ifndef AOC_TIMER_HPP
#define AOC_TIMER_HPP

#include <chrono>
#include <iostream>
#include <string>

class Timer
{
public:
    explicit Timer(const std::string &name = "Code")
        : name(name), start(std::chrono::high_resolution_clock::now()) {}

    ~Timer()
    {
        auto end = std::chrono::high_resolution_clock::now();
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cerr << name << " executed in: " << us << " µs\n";
    }

private:
    std::string name;
    std::chrono::high_resolution_clock::time_point start;
};

#define MEASURE_TIME Timer timer(__FUNCTION__);

#endif // AOC_TIMER_HPP