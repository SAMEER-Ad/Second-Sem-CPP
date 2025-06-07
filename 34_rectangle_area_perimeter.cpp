#include <iostream>
using namespace std;

int main() {
    cout << "Samir Adhikari" << endl;
    
    float l, w, a, p;
    
    cout << "Enter length of rectangle: ";
    cin >> l;
    cout << "Enter width of rectangle: ";
    cin >> w;
    
    a = l * w;
    p = 2 * (l + w);
    
    cout << "Area of rectangle = " << a << " square units" << endl;
    cout << "Perimeter of rectangle = " << p << " units" << endl;
    
    return 0;
}
