#include <iostream>
#include <memory>
#include <string>

class Car {
private:
    std::string brand;
    std::string model;
    int speed;

public:
    Car(const std::string& brand, const std::string& model)
        : brand(brand), model(model), speed(0) {}

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

int main() {
    std::unique_ptr<Car> car = std::make_unique<Car>("Toyota", "Corolla");
    car->accelerate(50);
    car->displayInfo();

    std::shared_ptr<Car> sharedCar = std::make_shared<Car>("Tesla", "Model S");
    sharedCar->accelerate(70);
    sharedCar->displayInfo();

    return 0;
}
