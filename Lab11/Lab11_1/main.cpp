#include <iostream>
#include <fstream>
#include <string>
#include <limits>

void createDataFile(const std::string& filename) {
    std::ofstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    int count;
    std::cout << "Enter the number of values to input: ";
    std::cin >> count;
    
    std::cout << "Enter " << count << " numbers: ";
    for (int i = 0; i < count; ++i) {
        double number;
        std::cin >> number;
        file << number << std::endl;
    }
    
    file.close();
    std::cout << "File " << filename << " created successfully." << std::endl;
}

void findMinMax(const std::string& filename, double& min, double& max) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    min = std::numeric_limits<double>::max();
    max = std::numeric_limits<double>::lowest();
    
    double number;
    while (file >> number) {
        if (number < min) min = number;
        if (number > max) max = number;
    }
    
    file.close();
}

double calculateMean(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 0;
    }
    
    double sum = 0;
    int count = 0;
    double number;
    
    while (file >> number) {
        sum += number;
        count++;
    }
    
    file.close();
    
    if (count > 0) {
        return sum / count;
    } else {
        return 0;
    }
}

void writeResults(const std::string& filename, double minMaxMean, double allMean) {
    std::ofstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    file << "Arithmetic mean of min and max: " << minMaxMean << std::endl;
    file << "Arithmetic mean of all values: " << allMean << std::endl;
    
    file.close();
    std::cout << "Results written to " << filename << " successfully." << std::endl;
}

void displayFileContents(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    std::cout << "Contents of file " << filename << ":" << std::endl;
    
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    
    file.close();
}

int main() {
    std::string inputFilename, outputFilename;
    
    std::cout << "Enter the name of the input file: ";
    std::cin >> inputFilename;
    
    std::cout << "Enter the name of the output file: ";
    std::cin >> outputFilename;
    
    createDataFile(inputFilename);
    
    double min, max;
    findMinMax(inputFilename, min, max);
    
    double minMaxMean = (min + max) / 2.0;
    
    double allMean = calculateMean(inputFilename);
    
    writeResults(outputFilename, minMaxMean, allMean);
    
    displayFileContents(outputFilename);
    
    return 0;
}
