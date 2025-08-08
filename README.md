Real-Time Sensor Data Simulator
Overview
This project is a C++ console application that simulates real-time sensor data streams, specifically temperature readings. It demonstrates key embedded and real-time programming concepts such as:

Generating noisy sensor data using random distributions

Real-time data processing using multithreading

Applying Moving Average and Kalman filters for noise reduction

Logging raw and filtered data to a CSV file for analysis

No physical hardware is required — the simulation runs entirely on your PC.

Features
Multithreaded sensor data simulation with predictable update intervals

Moving Average filter to smooth short-term noise

Kalman filter for advanced noise reduction and state estimation

CSV logging of raw and filtered sensor data for offline analysis

Getting Started
Prerequisites
Visual Studio 2019 or later with C++ workload installed

Alternatively, a C++ compiler such as clang++ or g++ supporting C++14

Build Instructions
Clone or download the repository

Open the project in Visual Studio or your preferred IDE

Build the project (e.g., press Ctrl+Shift+B in Visual Studio)

Run the executable

Alternatively, from the command line:

bash
Copy
Edit
clang++ -std=c++14 main.cpp filters.cpp logger.cpp -o SensorSimulator
./SensorSimulator
Usage
When you run the program, it will display:

vbnet
Copy
Edit
Press Enter to stop...
The program generates simulated sensor readings and logs them continuously to sensor_log.csv.

Press Enter anytime to stop the simulation and close the CSV file.

Open sensor_log.csv with Excel, Google Sheets, or any CSV viewer to analyze the sensor data.

Project Structure
graphql
Copy
Edit
/RealTimeSensorSimulator
  ├─ filters.h       # Moving Average and Kalman filter declarations
  ├─ filters.cpp     # Filter implementations
  ├─ logger.h        # CSV logging class declaration
  ├─ logger.cpp      # CSV logging implementation
  └─ main.cpp        # Program entry point and thread management
Resume Highlights
Developed a multithreaded C++ real-time sensor simulator generating noisy data and applying signal filters.

Implemented Moving Average and Kalman filters to improve data quality.

Designed a CSV logging system for sensor data analysis.

License
MIT License
