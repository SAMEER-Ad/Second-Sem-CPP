#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    int n, t1 = 0, t2 = 1, nt = 0;
    
    cout << "Enter the number of terms: ";
    cin >> n;
    
    cout << "Fibonacci Series: ";
    
    if (n == 0) {
        cout << "No terms to display." << endl;
    } else if (n == 1) {
        cout << t1 << endl;
    } else {
        cout << t1 << ", " << t2;
        
        for (int i = 3; i <= n; ++i) {
            nt = t1 + t2;
            cout << ", " << nt;
            t1 = t2;
            t2 = nt;
        }
        cout << endl;
    }
    
    return 0;
}
