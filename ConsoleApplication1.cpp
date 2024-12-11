#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

const double PI = 3.141592653589793;

// Function to generate sinusoidal values
std::vector<double> generateSin(double amplitude, double frequency, double samplingRate, int points) {
    std::vector<double> values;
    for (int i = 0; i < points; ++i) {
        double t = i * samplingRate;
        values.push_back(amplitude * sin(2 * PI * frequency * t));
    }
    return values;
}

// Function to generate cosinusoidal values
std::vector<double> generateCos(double amplitude, double frequency, double samplingRate, int points) {
    std::vector<double> values;
    for (int i = 0; i < points; ++i) {
        double t = i * samplingRate;
        values.push_back(amplitude * cos(2 * PI * frequency * t));
    }
    return values;
}

// Function to write data to a CSV file
void writeCSV(const std::string& filename, const std::vector<double>& time, const std::vector<double>& sinValues, const std::vector<double>& cosValues) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Time,Sin,Cos\n";
        for (size_t i = 0; i < time.size(); ++i) {
            file << time[i] << "," << sinValues[i] << "," << cosValues[i] << "\n";
        }
        file.close();
        std::cout << "Data written to " << filename << std::endl;
    }
    else {
        std::cerr << "Error opening file!" << std::endl;
    }
}

int main() {
    // Input parameters
    double amplitude, frequency, samplingRate;
    int points;
    std::string filename;

    std::cout << "Enter amplitude: ";
    std::cin >> amplitude;
    std::cout << "Enter frequency (Hz): ";
    std::cin >> frequency;
    std::cout << "Enter sampling rate (seconds): ";
    std::cin >> samplingRate;
    std::cout << "Enter number of points: ";
    std::cin >> points;
    std::cout << "Enter output filename (with .csv extension): ";
    std::cin >> filename;

    // Generate time vector
    std::vector<double> time;
    for (int i = 0; i < points; ++i) {
        time.push_back(i * samplingRate);
    }

    // Generate function values
    std::vector<double> sinValues = generateSin(amplitude, frequency, samplingRate, points);
    std::vector<double> cosValues = generateCos(amplitude, frequency, samplingRate, points);

    // Write to CSV
    writeCSV(filename, time, sinValues, cosValues);

    return 0;
}klglksgölsföslkf
yo yo 