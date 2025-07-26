/*
Question 14: Build a graphics editor where Shape is an abstract class with methods draw() and resize(). 
Implement Rectangle, Circle, and Triangle classes. Store shapes in an array of base class pointers 
and loop to call draw() on each.
*/

#include <iostream>
using namespace std;

class Shape {
protected:
    double x, y;  // Position
    string color;
public:
    Shape(double x_pos, double y_pos, string col) : x(x_pos), y(y_pos), color(col) {}
    
    virtual void draw() = 0;
    virtual void resize(double factor) = 0;
    
    virtual void showInfo() {
        cout << "Position: (" << x << ", " << y << "), Color: " << color << endl;
    }
    
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double x, double y, string col, double w, double h) 
        : Shape(x, y, col), width(w), height(h) {}
    
    void draw() override {
        cout << "Drawing Rectangle:" << endl;
        showInfo();
        cout << "Dimensions: " << width << " x " << height << endl;
        cout << "Area: " << (width * height) << endl;
    }
    
    void resize(double factor) override {
        width *= factor;
        height *= factor;
        cout << "Rectangle resized by factor " << factor << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double x, double y, string col, double r) 
        : Shape(x, y, col), radius(r) {}
    
    void draw() override {
        cout << "Drawing Circle:" << endl;
        showInfo();
        cout << "Radius: " << radius << endl;
        cout << "Area: " << (3.14159 * radius * radius) << endl;
    }
    
    void resize(double factor) override {
        radius *= factor;
        cout << "Circle resized by factor " << factor << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double x, double y, string col, double b, double h) 
        : Shape(x, y, col), base(b), height(h) {}
    
    void draw() override {
        cout << "Drawing Triangle:" << endl;
        showInfo();
        cout << "Base: " << base << ", Height: " << height << endl;
        cout << "Area: " << (0.5 * base * height) << endl;
    }
    
    void resize(double factor) override {
        base *= factor;
        height *= factor;
        cout << "Triangle resized by factor " << factor << endl;
    }
};

int main() {
    // Create array of Shape pointers for polymorphism
    Shape* shapes[] = {
        new Rectangle(10, 20, "Blue", 15, 10),
        new Circle(50, 30, "Red", 8),
        new Triangle(5, 15, "Green", 12, 9),
        new Rectangle(25, 35, "Yellow", 20, 8)
    };
    
    int numShapes = 4;
    
    cout << "Graphics Editor - Drawing Shapes:\n" << endl;
    
    // Draw all shapes polymorphically
    for (int i = 0; i < numShapes; i++) {
        cout << "Shape " << (i + 1) << ":" << endl;
        shapes[i]->draw();
        cout << "\n";
    }
    
    cout << "Resizing all shapes by factor 1.5:\n" << endl;
    
    // Resize all shapes
    for (int i = 0; i < numShapes; i++) {
        shapes[i]->resize(1.5);
    }
    
    cout << "\nAfter resizing:" << endl;
    
    // Draw all shapes again
    for (int i = 0; i < numShapes; i++) {
        cout << "\nShape " << (i + 1) << ":" << endl;
        shapes[i]->draw();
    }
    
    // Clean up memory
    for (int i = 0; i < numShapes; i++) {
        delete shapes[i];
    }
    
    return 0;
}
