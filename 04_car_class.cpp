// 4. Create a class Car that includes members for brand, model, and year. Add a method to display car details and another to update the year.
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand, model;
    int year;

public:
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }
    
    void display() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
    
    void updateYear(int newYear) {
        year = newYear;
        cout << "Year updated to: " << year << endl;
    }
};

int main() {
    string brand, model;
    int year, newYear;
    
    cout << "Enter car brand: ";
    getline(cin, brand);
    cout << "Enter model: ";
    getline(cin, model);
    cout << "Enter year: ";
    cin >> year;
    
    Car car(brand, model, year);
    
    cout << "\nCar Details:" << endl;
    car.display();
    
    cout << "\nEnter new year: ";
    cin >> newYear;
    car.updateYear(newYear);
    
    cout << "\nUpdated Details:" << endl;
    car.display();
    
    return 0;
}
