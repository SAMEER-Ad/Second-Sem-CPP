#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int n1, n2, gcd, lcm;
    
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;
    
    // Calculate GCD directly in main
    int a = n1;
    int b = n2;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;
    
    // Calculate LCM using formula: LCM = (n1 * n2) / GCD
    lcm = (n1 * n2) / gcd;
    
    cout << "LCM of " << n1 << " and " << n2 << " is: " << lcm << endl;
    
    return 0;
}
