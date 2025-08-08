#pragma once
#include <fstream>
#include <string>

class Logger {
    std::ofstream file;
public:
    Logger(const std::string &filename);
    void log(double raw, double ma, double kalman);
    ~Logger();
};