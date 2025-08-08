#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include <atomic>
#include "filters.h"
#include "logger.h"

std::atomic<bool> running(true);

double generateSensorData(double base, double noiseLevel) {
    static std::default_random_engine eng(std::random_device{}());
    std::normal_distribution<double> dist(base, noiseLevel);
    return dist(eng);
}

void sensorThread(MovingAverage &ma, KalmanFilter &kf, Logger &logger) {
    while (running) {
        double rawTemp = generateSensorData(25.0, 0.5);
        double maVal = ma.update(rawTemp);
        double kalVal = kf.update(rawTemp);
        logger.log(rawTemp, maVal, kalVal);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    MovingAverage ma(5);
    KalmanFilter kf(0.01, 0.1);
    Logger logger("sensor_log.csv");

    std::thread t(sensorThread, std::ref(ma), std::ref(kf), std::ref(logger));
    std::cout << "Press Enter to stop..." << std::endl;
    std::cin.get();
    running = false;
    t.join();
    return 0;
}