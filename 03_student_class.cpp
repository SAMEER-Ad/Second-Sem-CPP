// 3. Define a class Student with attributes rollNo, name, and marks for three subjects. Write a method to calculate and display the average marks.
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    double marks[3];

public:
    void input() {
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }
    
    double average() {
        double sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += marks[i];
        }
        return sum / 3;
    }
    
    void display() {
        cout << "\nStudent Details:" << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Average: " << average() << endl;
    }
};

int main() {
    Student s;
    s.input();
    s.display();
    return 0;
}
