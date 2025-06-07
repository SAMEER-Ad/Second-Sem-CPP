#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int age;
    
    cout << "Enter your age: ";
    cin >> age;
    
    if (age >= 18) {
        cout << "You are eligible to vote." << endl;
    } else {
        cout << "You are not eligible to vote." << endl;
    }
    
    return 0;
}
