// 5. Write a class Time with attributes hours, minutes, and seconds. Include methods to set time, display it in hh:mm:ss format, and add two Time objects.
#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }
    
    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }
    
    void display() {
        cout << setfill('0') << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << endl;
    }
    
    Time add(Time t) {
        Time result;
        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes + result.seconds / 60;
        result.hours = hours + t.hours + result.minutes / 60;
        
        result.seconds %= 60;
        result.minutes %= 60;
        result.hours %= 24;
        
        return result;
    }
};

int main() {
    int h1, m1, s1, h2, m2, s2;
    
    cout << "Enter first time (h m s): ";
    cin >> h1 >> m1 >> s1;
    cout << "Enter second time (h m s): ";
    cin >> h2 >> m2 >> s2;
    
    Time t1(h1, m1, s1);
    Time t2(h2, m2, s2);
    
    cout << "\nFirst time: ";
    t1.display();
    cout << "Second time: ";
    t2.display();
    
    Time sum = t1.add(t2);
    cout << "Sum: ";
    sum.display();
    
    return 0;
}
