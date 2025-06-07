#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int n, sum = 0;
    
    cout << "Enter a positive integer (N): ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    
    cout << "Sum of first " << n << " natural numbers: " << sum << endl;
    
    return 0;
}
