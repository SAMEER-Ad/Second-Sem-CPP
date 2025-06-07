// 1. Create a class Rectangle with private members length and width. Write methods to set dimensions, calculate area, and perimeter.
#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }
    
    double area() {
        return length * width;
    }
    
    double perimeter() {
        return 2 * (length + width);
    }
    
    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    Rectangle rect;
    double l, w;
    
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter width: ";
    cin >> w;
    
    rect.setDimensions(l, w);
    rect.display();
    
    return 0;
}
