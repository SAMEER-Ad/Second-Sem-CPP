#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int num;
    
    cout << "Enter a number: ";
    cin >> num;
    
    cout << "Multiplication table for " << num << ":" << endl;
    
    for (int i = 1; i <= 10; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
    
    return 0;
}
