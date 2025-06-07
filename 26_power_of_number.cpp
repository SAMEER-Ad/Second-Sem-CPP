#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int b, ex;
    long long result = 1;
    
    cout << "Enter base: ";
    cin >> b;
    cout << "Enter exponent (positive integer): ";
    cin >> ex;
    
    if (ex < 0) {
        cout << "Please enter a positive exponent." << endl;
    } else {
        for (int i = 1; i <= ex; i++) {
            result *= b;
        }
        
        cout << b << " raised to the power " << ex << " = " << result << endl;
    }
    
    return 0;
}
