#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if (number % 3 == 0 && number % 5 == 0) {
        cout << "The number is divisible by both 3 and 5." << endl;
    } else {
        cout << "The number is not divisible by both 3 and 5." << endl;
    }
    
    return 0;
}
