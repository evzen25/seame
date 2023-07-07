#include <iostream>
#include <string>

// Abstraction: we create abstract class "Vehicle", which describes general characteristics and methods for all kind of transport
class Vehicle {
protected:
    std::string brand;

public:
    Vehicle(const std::string& brand) : brand(brand) {}

    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
};

// Inharitance: we create class "Car", which inherits class "Vehicle"
class Car : public Vehicle {
protected:
    std::string model;
    int speed;

public:
    Car(const std::string& brand, const std::string& model) : Vehicle(brand), model(model), speed(0) {}

    // Encapsulation: we hide details of realization and demostrate public methods for work with the object
    void startEngine() override {
        std::cout << "Starting the car engine" << std::endl;
    }

    void stopEngine() override {
        std::cout << "Stopping the car engine" << std::endl;
    }

    void accelerate(int speed) {
        this->speed += speed;
    }

    void brake(int speed) {
        this->speed -= speed;
    }

    int getSpeed() const {
        return speed;
    }

    void displayInfo() const {
        std::cout << "Brand: " << brand << ", Model: " << model << ", Speed: " << speed << std::endl;
    }
};

// Polymorphism: we create class "ElectricCar", which inherits class "Car" and redirects some methods
class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(const std::string& brand, const std::string& model, int batteryCapacity)
        : Car(brand, model), batteryCapacity(batteryCapacity) {}

    void startEngine() override {
        std::cout << "Starting the electric car" << std::endl;
    }

    void stopEngine() override {
        std::cout << "Stopping the electric car" << std::endl;
    }

    void displayInfo() const override {
        std::cout << "Brand: " << brand << ", Model: " << model << ", Speed: " << speed
            << ", Battery Capacity: " << batteryCapacity << std::endl;
    }
};

// Modularity: we create function main(), where create examples of different classes and call their methods
int main() {
    Car car("Toyota", "Corolla");
    car.startEngine();
    car.accelerate(50);
    car.displayInfo();
    car.brake(20);
    car.displayInfo();
    car.stopEngine();

    std::cout << std::endl;

    ElectricCar electricCar("Tesla", "Model S", 75);
    electricCar.startEngine();
    electricCar.accelerate(70);
    electricCar.displayInfo();
    electricCar.brake(30);
    electricCar.displayInfo();
    electricCar.stopEngine();

    return 0;
}
