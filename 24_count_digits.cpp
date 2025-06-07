#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int n, c = 0;
    
    cout << "Enter a positive integer: ";
    cin >> n;
    
    if (n == 0) {
        cout << "Number of digits: 1" << endl;
    } else {
        int temp = abs(n);
        while (temp > 0) {
            c++;
            temp /= 10;
        }
        cout << "Number of digits in " << n << " is: " << c << endl;
    }
    
    return 0;
}
