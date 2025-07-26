/*
Question 2: Model a simple Employee system: Base class Employee has name, id, and calculateSalary(). 
Derive FullTimeEmployee and PartTimeEmployee, each with their own implementation of calculateSalary().
*/

#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}
    
    virtual double calculateSalary() = 0;
    
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << calculateSalary() << endl;
    }
};

class FullTimeEmployee : public Employee {
private:
    double monthlySal;
public:
    FullTimeEmployee(string n, int i, double sal) : Employee(n, i), monthlySal(sal) {}
    
    double calculateSalary() override {
        return monthlySal;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    PartTimeEmployee(string n, int i, double rate, int hrs) : Employee(n, i), hourlyRate(rate), hoursWorked(hrs) {}
    
    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};

int main() {
    FullTimeEmployee ft("John", 101, 5000);
    PartTimeEmployee pt("Alice", 102, 25, 80);
    
    ft.display();
    pt.display();
    
    return 0;
}
