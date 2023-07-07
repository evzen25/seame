#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;

public:
    Car() {
        make = "";
        model = "";
        year = 0;
        std::cout << "Car default constructor called." << std::endl;
    }

    Car(const std::string& make, const std::string& model, int year) {
        this->make = make;
        this->model = model;
        this->year = year;
        std::cout << "Car parameterized constructor called." << std::endl;
    }

    Car(const Car& other) {
        make = other.make;
        model = other.model;
        year = other.year;
        std::cout << "Car copy constructor called." << std::endl;
    }

    Car& operator=(const Car& other) {
        if (this != &other) {
            make = other.make;
            model = other.model;
            year = other.year;
        }
        std::cout << "Car copy assignment operator called." << std::endl;
        return *this;
    }

    ~Car() {
        std::cout << "Car destructor called." << std::endl;
    }

    void drive() {
        std::cout << "Driving " << make << " " << model << " " << year << " edition." << std::endl;
    }
};

class SportsCar : public Car {
private:
    int topSpeed;

public:
    SportsCar() : Car() {
        topSpeed = 0;
        std::cout << "SportsCar default constructor called." << std::endl;
    }

    SportsCar(const std::string& make, const std::string& model, int year, int topSpeed) : Car(make, model, year) {
        this->topSpeed = topSpeed;
        std::cout << "SportsCar parameterized constructor called." << std::endl;
    }

    SportsCar(const SportsCar& other) : Car(other) {
        topSpeed = other.topSpeed;
        std::cout << "SportsCar copy constructor called." << std::endl;
    }

    SportsCar& operator=(const SportsCar& other) {
        if (this != &other) {
            Car::operator=(other);
            topSpeed = other.topSpeed;
        }
        std::cout << "SportsCar copy assignment operator called." << std::endl;
        return *this;
    }

    ~SportsCar() {
        std::cout << "SportsCar destructor called." << std::endl;
    }

    void drive() {
        Car::drive();
        std::cout << "Speed: " << topSpeed << " mph." << std::endl;
    }
};

int main() {
    Car myCar("Toyota", "Camry", 2022);
    myCar.drive();

    std::cout << "------------------------" << std::endl;

    SportsCar mySportsCar("Ferrari", "458 Italia", 2021, 200);
    mySportsCar.drive();

    return 0;
}
