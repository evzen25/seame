#include <iostream>
#include <string>

class Car {
private:
    std::string name;
    int speed;

public:
    // Default constructor
    Car() : name(""), speed(0) {}

    // Parameterized constructor
    Car(const std::string& name, int speed) : name(name), speed(speed) {}

    // Copy constructor
    Car(const Car& other) : name(other.name), speed(other.speed) {}

    // Copy assignment operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            name = other.name;
            speed = other.speed;
        }
        return *this;
    }

    // Destructor
    ~Car() {
        // Perform any necessary cleanup or resource deallocation here
    }

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Getter for speed
    int getSpeed() const {
        return speed;
    }
};

int main() {
    // Create a car object using the default constructor
    Car car1;
    std::cout << "Car 1 Name: " << car1.getName() << ", Speed: " << car1.getSpeed() << std::endl;

    // Create a car object using the parameterized constructor
    Car car2("BMW", 200);
    std::cout << "Car 2 Name: " << car2.getName() << ", Speed: " << car2.getSpeed() << std::endl;

    // Create a car object using the copy constructor
    Car car3 = car2;
    std::cout << "Car 3 Name: " << car3.getName() << ", Speed: " << car3.getSpeed() << std::endl;

    // Assign car2 to car1 using the copy assignment operator
    car1 = car2;
    std::cout << "Car 1 Name: " << car1.getName() << ", Speed: " << car1.getSpeed() << std::endl;

    return 0;
}
