#include "filters.h"
#include <numeric>

MovingAverage::MovingAverage(size_t size) : maxSize(size) {}

double MovingAverage::update(double value) {
    if (window.size() >= maxSize) window.erase(window.begin());
    window.push_back(value);
    return std::accumulate(window.begin(), window.end(), 0.0) / window.size();
}

KalmanFilter::KalmanFilter(double processNoise, double measurementNoise)
    : Q(processNoise), R(measurementNoise), P(1), X(0), K(0) {}

double KalmanFilter::update(double measurement) {
    P += Q;
    K = P / (P + R);
    X += K * (measurement - X);
    P *= (1 - K);
    return X;
}