#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int c;
    int a[2][2], b[2][2], r[2][2];
    
    do {
        cout << "\nMatrix Operations (2x2 Matrices):" << endl;
        cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Exit\n> ";
        cin >> c;
        
        if(c >= 1 && c <= 3) {
            // Input first matrix
            cout << "Enter elements of first 2x2 matrix:" << endl;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    cout << "[" << i << "][" << j << "]: ";
                    cin >> a[i][j];
                }
            }
            
            // Input second matrix
            cout << "Enter elements of second 2x2 matrix:" << endl;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    cout << "[" << i << "][" << j << "]: ";
                    cin >> b[i][j];
                }
            }
            
            // Perform the operation
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    if(c == 1) { // Addition
                        r[i][j] = a[i][j] + b[i][j];
                    } else if(c == 2) { // Subtraction
                        r[i][j] = a[i][j] - b[i][j];
                    } else if(c == 3) { // Multiplication
                        r[i][j] = 0;
                        for(int k = 0; k < 2; k++) {
                            r[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
            }
            
            
            // Display result matrix with operation name
            const char* op;
            if (c == 1) {
                op = "Addition";
            } else if (c == 2) {
                op = "Subtraction";
            } else {
                op = "Multiplication";
            }
            cout << "Result of " << op << ":" << endl;
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    cout << r[i][j] << "\t";
                }
                cout << endl;
            }
        } else if(c == 4) {
            cout << "Bye see u" << endl;
        } else {
            cout << "Invalid choice! Please enter 1-4." << endl;
        }
    } while(c != 4);
    
    return 0;
}
