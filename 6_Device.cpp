/*
Question 6: Design a class Device with basic specs like model and brand. Derive Laptop and Mobile, 
which include additional features. Demonstrate access to base class private/protected members via inheritance.
*/

#include <iostream>
using namespace std;

class Device {
private:
    string sNo;  // Private member
protected:
    string model, brand; // Protected - accessible to derived classes
    double price;
public:
    Device(string s, string m, string b, double p) : sNo(s), model(m), brand(b), price(p) {}
    string getSerialNo() { return sNo; }
};

class Laptop : public Device {
private:
    int ram;
    string proc;
public:
    Laptop(string s, string m, string b, double p, int r, string pr) 
        : Device(s, m, b, p), ram(r), proc(pr) {}
    
    void displaySpecs() {
        cout << "Laptop - " << brand << " " << model << ", RAM: " << ram 
             << "GB, CPU: " << proc << ", $" << price << ", S/N: " << getSerialNo() << endl;
    }
    
    void upgrade(int newRam) {
        ram = newRam;
        cout << "RAM upgraded to " << ram << "GB" << endl;
    }
};

class Mobile : public Device {
private:
    string os;
    int storage;
public:
    Mobile(string s, string m, string b, double p, string o, int st) 
        : Device(s, m, b, p), os(o), storage(st) {}
    
    void displaySpecs() {
        cout << "Mobile - " << brand << " " << model << ", OS: " << os 
             << ", Storage: " << storage << "GB, $" << price << ", S/N: " << getSerialNo() << endl;
    }
    
    void installApp(string app) {
        cout << "Installing " << app << " on " << brand << " " << model << endl;
    }
};

int main() {
    Laptop l("L001", "ThinkPad X1", "Lenovo", 1500, 16, "Intel i7");
    Mobile m("M001", "Galaxy S24", "Samsung", 900, "Android", 256);
    
    l.displaySpecs();
    l.upgrade(32);
    m.displaySpecs();
    m.installApp("WhatsApp");
    
    return 0;
}
