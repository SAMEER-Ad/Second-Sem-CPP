#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    float c, f;
    
    cout << "Enter temperature in Celsius: ";
    cin >> c;
    
    // Convert Celsius to Fahrenheit
    f = (c * 9.0/5.0) + 32;
    
    cout << c << " degrees Celsius is equal to " << f << " degrees Fahrenheit." << endl;
    
    return 0;
}
