// 8. Define a class Temperature that stores temperature in Celsius and provides a method to convert it to Fahrenheit.
#include <iostream>
using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature(double c = 0) {
        celsius = c;
    }
    
    void setCelsius(double c) {
        celsius = c;
    }
    
    double toFahrenheit() {
        return (celsius * 9.0 / 5.0) + 32;
    }
    
    void display() {
        cout << "Celsius: " << celsius << " Degree C" << endl;
        cout << "Fahrenheit: " << toFahrenheit() << " Degree F" << endl;
    }
};

int main() {
    double temp;
    
    cout << "Enter temperature in Celsius: ";
    cin >> temp;
    
    Temperature t(temp);
    t.display();
    
    return 0;
}
