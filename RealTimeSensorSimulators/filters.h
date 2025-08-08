#pragma once
#include <vector>

class MovingAverage {
    std::vector<double> window;
    size_t maxSize;
public:
    MovingAverage(size_t size);
    double update(double value);
};

class KalmanFilter {
    double Q, R, P, X, K;
public:
    KalmanFilter(double processNoise, double measurementNoise);
    double update(double measurement);
};