#include <iostream>
#include <cmath>

// Arrays to store the inputs and results
double inputs[4];  // [0] = A0, [1] = N0, [2] = M0, [3] = lambda
double results[3]; // [0] = A(t), [1] = N(t), [2] = M(t)

// Function declarations
double calculateAt(double a0, double lambda, double t);  // A(t)
double calculateNt(double n0, double lambda, double t);  // N(t)
double calculateMt(double m0, double lambda, double t);  // M(t)

int main() {
    int choice;  // Variable to store the user's choice
    double t;    // Variable to store the time value (t)

    // Display welcome message and choices
    std::cout << "Welcome to the nuclear calculations :)\n";
    std::cout << "Choose one of the following calculations:\n";
    std::cout << "1. A(t) (Activity)\n";
    std::cout << "2. N(t) (Number of particles)\n";
    std::cout << "3. M(t) (Mass)\n";
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    // Ask for lambda (decay constant) and time (t), which are needed for all calculations
    std::cout << "Enter lambda (decay constant): ";
    std::cin >> inputs[3];  // Store lambda in position 3 of the inputs array
    std::cout << "Enter time (t) in seconds: ";
    std::cin >> t;  // Store time in variable t

    switch (choice) {
        case 1: // If the user chooses A(t)
            std::cout << "You are calculating A(t)\n";
            std::cout << "Enter A0 (initial activity): ";
            std::cin >> inputs[0];  // Store A0 in position 0 of the inputs array

            results[0] = calculateAt(inputs[0], inputs[3], t);  // Calculate A(t)
            std::cout << "The value of A(t): " << results[0] << " units\n";
            break;

        case 2: // If the user chooses N(t)
            std::cout << "You are calculating N(t)\n";
            std::cout << "Enter N0 (initial number): ";
            std::cin >> inputs[1];  // Store N0 in position 1 of the inputs array

            results[1] = calculateNt(inputs[1], inputs[3], t);  // Calculate N(t)
            std::cout << "The value of N(t): " << results[1] << " units\n";
            break;

        case 3: // If the user chooses M(t)
            std::cout << "You are calculating M(t)\n";
            std::cout << "Enter M0 (initial mass): ";
            std::cin >> inputs[2];  // Store M0 in position 2 of the inputs array

            results[2] = calculateMt(inputs[2], inputs[3], t);  // Calculate M(t)
            std::cout << "The value of M(t): " << results[2] << " units\n";
            break;

        default:  // If the user enters an invalid choice
            std::cout << "Invalid choice. Please select 1, 2, or 3.\n";
            break;
    }

    return 0;
}

// Function to calculate A(t) and return the result
double calculateAt(double a0, double lambda, double t) {
    return a0 * std::exp(-lambda * t);  // Calculate and return A(t)
}

// Function to calculate N(t) and return the result
double calculateNt(double n0, double lambda, double t) {
    return n0 * std::exp(-lambda * t);  // Calculate and return N(t)
}

// Function to calculate M(t) and return the result
double calculateMt(double m0, double lambda, double t) {
    return m0 * std::exp(-lambda * t);  // Calculate and return M(t)
}


