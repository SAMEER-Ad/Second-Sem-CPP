#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int num, sum = 0, digit;
    
    cout << "Enter a number: ";
    cin >> num;
    
    int temp = num;
    while (temp != 0) {
        digit = temp % 10;
        sum += digit;
        temp /= 10;
    }
    
    cout << "Sum of digits of " << num << " = " << sum << endl;
    
    return 0;
}
