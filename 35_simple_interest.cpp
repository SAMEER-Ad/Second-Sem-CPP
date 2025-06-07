#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    float p, r, t, i;
    
    cout << "Enter principal amount: ";
    cin >> p;
    cout << "Enter rate of interest (per annum): ";
    cin >> r;
    cout << "Enter time period (in years): ";
    cin >> t;
    
    // Calculate simple interest
    i = (p * r * t) / 100;
    
    cout << "Simple Interest = " << i << endl;
    cout << "Total Amount = " << p + i << endl;
    
    return 0;
}
