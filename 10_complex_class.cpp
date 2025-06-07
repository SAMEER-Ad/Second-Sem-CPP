// 10. Write a class Complex to represent complex numbers. Include methods to input, display, and add two complex numbers.
#include <iostream>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }
    
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }
    
    void display() {
        if (imag >= 0) {
            cout << real << " + " << imag << "i";
        } else {
            cout << real << " - " << -imag << "i";
        }
    }
    
    Complex add(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }
};

int main() {
    Complex c1, c2;
    
    cout << "Enter first complex number:" << endl;
    c1.input();
    
    cout << "\nEnter second complex number:" << endl;
    c2.input();
    
    cout << "\nFirst complex number: ";
    c1.display();
    cout << "\nSecond complex number: ";
    c2.display();
    
    Complex sum = c1.add(c2);
    cout << "\nSum: ";
    sum.display();
    cout << endl;
    
    return 0;
}
