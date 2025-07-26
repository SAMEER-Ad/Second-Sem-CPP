/*
Question 4: Implement a vehicle registration system. Base class Vehicle, derived classes Car, Motorcycle, 
and Truck should override the method calculateTax() based on engine size and category.
*/

#include <iostream>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double engineSize;
    string owner;
public:
    Vehicle(string reg, double eng, string own) : regNo(reg), engineSize(eng), owner(own) {}
    
    virtual double calculateTax() = 0;
    
    void displayInfo() {
        cout << "Reg No: " << regNo << ", Owner: " << owner 
             << ", Engine: " << engineSize << "L, Tax: $" << calculateTax() << endl;
    }
};

class Car : public Vehicle {
public:
    Car(string reg, double eng, string own) : Vehicle(reg, eng, own) {}
    
    double calculateTax() override {
        // Car tax: $50 per liter + base $200
        return (engineSize * 50) + 200;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(string reg, double eng, string own) : Vehicle(reg, eng, own) {}
    
    double calculateTax() override {
        // Motorcycle tax: $30 per liter + base $100
        return (engineSize * 30) + 100;
    }
};

class Truck : public Vehicle {
public:
    Truck(string reg, double eng, string own) : Vehicle(reg, eng, own) {}
    
    double calculateTax() override {
        // Truck tax: $100 per liter + base $500
        return (engineSize * 100) + 500;
    }
};

int main() {
    Car c("CAR123", 2.0, "John Doe");
    Motorcycle m("BIKE456", 0.8, "Alice Smith");
    Truck t("TRUCK789", 5.0, "Bob Transport");
    
    cout << "Vehicle Registration Tax Calculation:\n";
    c.displayInfo();
    m.displayInfo();
    t.displayInfo();
    
    return 0;
}
