#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int year;
    
    cout << "Enter a year: ";
    cin >> year;
    
    // Leap year condition: divisible by 4 and not divisible by 100, or divisible by 400
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }
    
    return 0;
}
