#include <iostream>

using namespace std;
#include <cctype>
int main() {
    cout << "Samir Adhikari" << endl;
    
    char ch;
    
    cout << "Enter a character: ";
    cin >> ch;
    
    ch = tolower(ch);
    
    if (isalpha(ch)) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            cout << "The character is a vowel." << endl;
        } else {
            cout << "The character is a consonant." << endl;
        }
    } else {
        cout << "The input is not an alphabet character." << endl;
    }
    
    return 0;
}
