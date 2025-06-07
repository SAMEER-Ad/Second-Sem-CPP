// 9. Create a class Calculator with methods for basic arithmetic operations (add, subtract, multiply, divide) that take two numbers as input.
#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }
    
    double subtract(double a, double b) {
        return a - b;
    }
    
    double multiply(double a, double b) {
        return a * b;
    }
    
    double divide(double a, double b) {
        if (b != 0) {
            return a / b;
        } else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
    
    void displayMenu() {
        cout << "\n1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Exit" << endl;
    }
};

int main() {
    Calculator calc;
    int choice;
    double a, b, result;
    
    do {
        calc.displayMenu();
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> a >> b;
            
            switch (choice) {
                case 1:
                    result = calc.add(a, b);
                    cout << "Result: " << result << endl;
                    break;
                case 2:
                    result = calc.subtract(a, b);
                    cout << "Result: " << result << endl;
                    break;
                case 3:
                    result = calc.multiply(a, b);
                    cout << "Result: " << result << endl;
                    break;                case 4:
                    result = calc.divide(a, b);
                    if (b != 0) {
                        cout << "Result: " << result << endl;
                    }
                    break;
            }
        }
    } while (choice != 5);
    
    return 0;
}
