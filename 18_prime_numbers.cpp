#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    cout << "Prime numbers from 1 to 100:" << endl;
    
    for (int num = 2; num <= 100; num++) {
        bool isPrime = true;
        
        // Check if num is divisible by any number from 2 to num-1
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        
        // If isPrime is still true, print the number
        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl;
    
    return 0;
}
