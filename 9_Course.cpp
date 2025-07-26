/*
Question 9: Simulate an academic system where Course is a base class and LabCourse and TheoryCourse are derived. 
Each overrides a method evaluate() with a different grading scheme.
*/

#include <iostream>
using namespace std;

class Course {
protected:
    string courseCode;
    string courseName;
    int credits;
    double marks;
public:
    Course(string code, string name, int cred, double m) 
        : courseCode(code), courseName(name), credits(cred), marks(m) {}
    
    virtual char evaluate() = 0;
    
    void displayCourse() {
        cout << "Course: " << courseCode << " - " << courseName 
             << " (" << credits << " credits)" << endl;
        cout << "Marks: " << marks << "/100, Grade: " << evaluate() << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(string code, string name, int cred, double m) 
        : Course(code, name, cred, m) {}
    
    char evaluate() override {
        // Lab courses have lenient grading (practical based)
        if (marks >= 80) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 60) return 'C';
        else if (marks >= 50) return 'D';
        else return 'F';
    }
};

class TheoryCourse : public Course {
public:
    TheoryCourse(string code, string name, int cred, double m) 
        : Course(code, name, cred, m) {}
    
    char evaluate() override {
        // Theory courses have strict grading
        if (marks >= 90) return 'A';
        else if (marks >= 80) return 'B';
        else if (marks >= 70) return 'C';
        else if (marks >= 60) return 'D';
        else return 'F';
    }
};

int main() {
    LabCourse lab("CS201L", "Programming Lab", 2, 75);
    TheoryCourse theory("CS201T", "Data Structures Theory", 3, 75);
    
    cout << "Academic Evaluation System:\n\n";
    
    cout << "=== Lab Course ===\n";
    lab.displayCourse();
    
    cout << "\n=== Theory Course ===\n";
    theory.displayCourse();
    
    cout << "\nNote: Same marks (75) but different grades due to different evaluation schemes!" << endl;
    
    return 0;
}
