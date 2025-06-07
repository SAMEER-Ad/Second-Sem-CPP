#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    string usr = "samir";
    string pwd = "password123";
    
    string inUsr, inPwd;
    int att = 0;
    bool ok = false;
    
    cout << "Login System (Max 3 attempts)" << endl;
    
    do {
        cout << "\nAttempt " << att + 1 << " of 3" << endl;
        cout << "Username: ";
        cin >> inUsr;
        cout << "Password: ";
        cin >> inPwd;
        
        if (inUsr == usr && inPwd == pwd) {
            ok = true;
            break;
        } else {
            cout << "Invalid username or password. Please try again." << endl;
            att++;
        }
    } while (att < 3);
    
    if (ok) {
        cout << "\nLogin successful! Welcome, " << usr << "!" << endl;
    } else {
        cout << "\nLogin failed after 3 attempts. Account locked." << endl;
    }
    
    return 0;

}
