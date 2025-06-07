/*
3. Write a function that takes two numbers and returns their greatest common divisor (GCD).
*/

#include <iostream>
using namespace std;

// Function to find the GCD using Euclidean algorithm
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

int main() {
    int num1, num2;
    cout << "Enter two numbers to find their GCD: ";
    cin >> num1 >> num2;
    
    // Handle negative numbers by taking absolute values
    num1 = abs(num1);
    num2 = abs(num2);
    
    cout << "GCD of " << num1 << " and " << num2 << " is: " << findGCD(num1, num2) << endl;
    
    return 0;
}
