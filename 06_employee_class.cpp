// 6. Design a class Employee with data members for id, name, salary. Add a method to apply a raise to the salary and display the updated details.
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    Employee(int i, string n, double s) {
        id = i;
        name = n;
        salary = s;
    }
    
    void applyRaise(double percent) {
        salary += salary * (percent / 100);
        cout << "Raise of " << percent << "% applied!" << endl;
    }
    
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    int id;
    string name;
    double salary, raise;
    
    cout << "Enter employee ID: ";
    cin >> id;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter salary: ";
    cin >> salary;
    
    Employee emp(id, name, salary);
    
    cout << "\nOriginal Details:" << endl;
    emp.display();
    
    cout << "\nEnter raise percentage: ";
    cin >> raise;
    emp.applyRaise(raise);
    
    cout << "\nUpdated Details:" << endl;
    emp.display();
    
    return 0;
}
