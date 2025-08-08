#include "logger.h"

Logger::Logger(const std::string &filename) {
    file.open(filename);
    file << "Raw,MovingAverage,Kalman\n";
}

void Logger::log(double raw, double ma, double kalman) {
    file << raw << "," << ma << "," << kalman << "\n";
}

Logger::~Logger() {
    if (file.is_open()) file.close();
}