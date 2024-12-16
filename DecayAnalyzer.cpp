#include <iostream>
#include <cmath>
#include <limits> 


double inputs[4];  // [0] = A0, [1] = N0, [2] = M0, [3] = lambda
double results[3]; // [0] = A(t), [1] = N(t), [2] = M(t)

// Function declarations
double calculateAt(double a0, double lambda, double t);  // A(t)
double calculateNt(double n0, double lambda, double t);  // N(t)
double calculateMt(double m0, double lambda, double t);  // M(t)

void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}

void displayWelcomeMessage() {
    std::cout << "\n=====================================\n";
    std::cout << "  Welcome to the Nuclear Calculator!   \n";
    std::cout << "=====================================\n";}

void displayMenu() {
    std::cout << "\nPlease choose one of the following calculations:\n";
    std::cout << "1. A(t) (Activity)\n";
    std::cout << "2. N(t) (Number of particles)\n";
    std::cout << "3. M(t) (Mass)\n";
    std::cout << "Enter your choice (1-3): ";}

int main() {
    int choice;
    double t; // Store the time value 

    displayWelcomeMessage();
    
    displayMenu();
    std::cin >> choice;
    
    // Validate choice
    while (choice < 1 || choice > 3 || std::cin.fail()) {
        std::cin.clear();
        clearInputBuffer();
        std::cout << "Invalid choice. Please select 1, 2, or 3: ";
        std::cin >> choice; }

    // Input decay constant and time
    std::cout << "\nEnter lambda (decay constant): ";
    std::cin >> inputs[3];
    while (inputs[3] <= 0 || std::cin.fail()) {
        std::cin.clear();
        clearInputBuffer();
        std::cout << "Invalid input. Lambda must be a positive number: ";
        std::cin >> inputs[3];}
    
    std::cout << "Enter time (t) in seconds: ";
    std::cin >> t;
    while (t < 0 || std::cin.fail()) {
        std::cin.clear();
        clearInputBuffer();
        std::cout << "Invalid input. Time must be a non-negative number: ";
        std::cin >> t; }

    // Perform calculation
    switch (choice) {
        case 1:
            std::cout << "\nYou chose to calculate A(t).\n";
            std::cout << "Enter A0 (initial activity): ";
            std::cin >> inputs[0];
            while (inputs[0] < 0 || std::cin.fail()) {
                std::cin.clear();
                clearInputBuffer();
                std::cout << "Invalid input. A0 must be a non-negative number: ";
                std::cin >> inputs[0]; }
            
            results[0] = calculateAt(inputs[0], inputs[3], t);
            std::cout << "\nThe value of A(t) is: " << results[0] << " units\n";
            break;

        case 2:
            std::cout << "\nYou chose to calculate N(t).\n";
            std::cout << "Enter N0 (initial number): ";
            std::cin >> inputs[1];
            while (inputs[1] < 0 || std::cin.fail()) {
                std::cin.clear();
                clearInputBuffer();
                std::cout << "Invalid input. N0 must be a non-negative number: ";
                std::cin >> inputs[1]; }
            
            results[1] = calculateNt(inputs[1], inputs[3], t);
            std::cout << "\nThe value of N(t) is: " << results[1] << " units\n";
            break;

        case 3:
            std::cout << "\nYou chose to calculate M(t).\n";
            std::cout << "Enter M0 (initial mass): ";
            std::cin >> inputs[2];
            while (inputs[2] < 0 || std::cin.fail()) {
                std::cin.clear();
                clearInputBuffer();
                std::cout << "Invalid input. M0 must be a non-negative number: ";
                std::cin >> inputs[2];
            }
            results[2] = calculateMt(inputs[2], inputs[3], t);
            std::cout << "\nThe value of M(t) is: " << results[2] << " units\n";
            break;

        default:
            std::cout << "Invalid choice. Please select 1, 2, or 3.\n";
            break;
    }

    return 0;
}

// Function to calculate A(t) and return the result
double calculateAt(double a0, double lambda, double t) {
    return a0 * std::exp(-lambda * t);
}

// Function to calculate N(t) and return the result
double calculateNt(double n0, double lambda, double t) {
    return n0 * std::exp(-lambda * t);
}

// Function to calculate M(t) and return the result
double calculateMt(double m0, double lambda, double t) {
    return m0 * std::exp(-lambda * t);
}



