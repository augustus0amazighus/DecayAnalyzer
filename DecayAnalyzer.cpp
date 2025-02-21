#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

constexpr double PLANCK_CONSTANT = 6.626e-34;

class QuantumEntity {
public:
    virtual void calculate() const = 0;
    virtual ~QuantumEntity() = default;
};

class Photon : public QuantumEntity {
    double frequency;
public:
    explicit Photon(double f) : frequency(f) {}
    void calculate() const override {
        std::cout << "Energy: " << PLANCK_CONSTANT * frequency << " J\n";
    }
};

class Particle : public QuantumEntity {
    double mass, velocity;
public:
    Particle(double m, double v) : mass(m), velocity(v) {}
    void calculate() const override {
        std::cout << "De Broglie Wavelength: " << PLANCK_CONSTANT / (mass * velocity) << " m\n";
    }
};

double getInput(const std::string& prompt) {
    double input;
    do {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail() || input <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again.\n";
        } else break;
    } while (true);
    return input;
}

int main() {
    while (true) {
        std::cout << "1- Photon Energy\n2- De Broglie Wavelength\n0- Exit\nChoice: ";
        int choice;
        std::cin >> choice;
        if (choice == 0) break;
        QuantumEntity* entity = (choice == 1) ? new Photon(getInput("Frequency (Hz): ")) : new Particle(getInput("Mass (kg): "), getInput("Velocity (m/s): "));
        entity->calculate();
        delete entity;
    }
}




