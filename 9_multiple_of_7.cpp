#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if (number % 7 == 0) {
        cout << "The number is a multiple of 7." << endl;
    } else {
        cout << "The number is not a multiple of 7." << endl;
    }
    
    return 0;
}
