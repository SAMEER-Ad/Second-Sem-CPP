/*
2. Create a function to check if a number is prime.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // 0 and 1 are not prime numbers
    if (n <= 1) {
        return false;
    }
    
    // Check from 2 to sqrt(n)
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int number;
    cout << "Enter a number to check if it's prime: ";
    cin >> number;
    
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }
    
    return 0;
}
