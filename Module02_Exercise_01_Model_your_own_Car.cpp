#include <iostream>
#include <string>

using namespace std;

// Base class for car parts
class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
};

// Engine class
class Engine : public Part {
public:
    void print() override {
        cout << "Engine: Opel Astra Engine\n";
    }
};

// Wheel class
class Wheel : public Part {
public:
    Wheel(const string& material, int size) : material_(material), size_(size) {}

    void print() override {
        cout << "Wheel: Material - " << material_ << ", Size - " << size_ << " inches\n";
    }

private:
    string material_;
    int size_;
};

// Brake class
class Brake : public Part {
public:
    Brake(const string& type) : type_(type) {}

    void print() override {
        cout << "Brake: Type - " << type_ << "\n";
    }

private:
    string type_;
};

// Transmission class
class Transmission : public Part {
public:
    Transmission(const string& type) : type_(type) {}

    void print() override {
        cout << "Transmission: Type - " << type_ << "\n";
    }

private:
    string type_;
};

// OpelAstra class representing the entire car
class OpelAstra {
public:
    OpelAstra() {
        engine_ = new Engine();
        wheels_ = new Wheel[4]{
            Wheel("Alloy", 17),
            Wheel("Alloy", 17),
            Wheel("Alloy", 17),
            Wheel("Alloy", 17)
        };
        brakes_ = new Brake[4]{
            Brake("Disc"),
            Brake("Disc"),
            Brake("Disc"),
            Brake("Disc")
        };
        transmission_ = new Transmission("Automatic");
    }

    void printDetails() {
        cout << "Opel Astra Details:\n";
        engine_->print();
        for (int i = 0; i < 4; ++i) {
            wheels_[i].print();
            brakes_[i].print();
        }
        transmission_->print();
    }

    ~OpelAstra() {
        delete engine_;
        delete[] wheels_;
        delete[] brakes_;
        delete transmission_;
    }

private:
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
};

int main() {
    OpelAstra myOpelAstra;
    myOpelAstra.printDetails();

    return 0;
}
