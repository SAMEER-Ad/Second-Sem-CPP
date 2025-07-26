/*
Question 3: Design a school system with a base class Person and derived classes Teacher, Student, and Administrator. 
Include shared and unique attributes and behaviors.
*/

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string id;
public:
    Person(string n, int a, string i) : name(n), age(a), id(i) {}
    
    virtual void displayInfo() {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age;
    }
    
    virtual void showRole() = 0;
};

class Teacher : public Person {
private:
    string subject;
    double salary;
public:
    Teacher(string n, int a, string i, string sub, double sal) 
        : Person(n, a, i), subject(sub), salary(sal) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << ", Subject: " << subject << ", Salary: $" << salary << endl;
    }
    
    void showRole() override {
        cout << name << " is a Teacher" << endl;
    }
    
    void teach() {
        cout << name << " is teaching " << subject << endl;
    }
};

class Student : public Person {
private:
    string grade;
    double gpa;
public:
    Student(string n, int a, string i, string g, double gp) 
        : Person(n, a, i), grade(g), gpa(gp) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << ", Grade: " << grade << ", GPA: " << gpa << endl;
    }
    
    void showRole() override {
        cout << name << " is a Student" << endl;
    }
    
    void study() {
        cout << name << " is studying" << endl;
    }
};

class Administrator : public Person {
private:
    string dept;
    string position;
public:
    Administrator(string n, int a, string i, string d, string pos) 
        : Person(n, a, i), dept(d), position(pos) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << ", Department: " << dept << ", Position: " << position << endl;
    }
    
    void showRole() override {
        cout << name << " is an Administrator" << endl;
    }
    
    void manage() {
        cout << name << " is managing " << dept << " department" << endl;
    }
};

int main() {
    Teacher t("Dr. Smith", 45, "T001", "Mathematics", 6000);
    Student s("Bob", 20, "S001", "Grade 12", 3.8);
    Administrator a("Ms. Johnson", 38, "A001", "Academic", "Dean");
    
    t.displayInfo();
    t.showRole();
    t.teach();
    
    cout << "\n";
    
    s.displayInfo();
    s.showRole();
    s.study();
    
    cout << "\n";
    
    a.displayInfo();
    a.showRole();
    a.manage();
    
    return 0;
}
