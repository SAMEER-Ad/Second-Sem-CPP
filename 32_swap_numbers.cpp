#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int a, b, t;
    
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    
    cout << "\nBefore swapping:" << endl;
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;
    
    t = a;
    a = b;
    b = t;
    
    cout << "\nAfter swapping:" << endl;
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;
    
    return 0;
}
