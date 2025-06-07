/*
5. Write a function to check whether a string is a palindrome.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to check if a string is palindrome
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        // Ignore non-alphanumeric characters
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        while (left < right && !isalnum(str[right])) {
            right--;
        }
        
        // Check if characters match (case-insensitive)
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        
        left++;
        right--;
    }
    
    return true;
}

int main() {
    string input;
    cout << "Enter a string to check if it's a palindrome: ";
    getline(cin, input);
    
    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }
    
    return 0;
}
