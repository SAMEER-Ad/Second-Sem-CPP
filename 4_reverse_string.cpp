/*
4. Create a function to reverse a string.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to reverse a string
string reverseString(const string& str) {
    string reversed;
    
    // Traverse the string from the end
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    
    return reversed;
}

int main() {
    string input;
    cout << "Enter a string to reverse: ";
    getline(cin, input);
    
    string reversed = reverseString(input);
    cout << "Reversed string: " << reversed << endl;
    
    return 0;
}
