/*
Question 11: Create a base class Notification with a virtual function send(). 
Subclasses EmailNotification, SMSNotification, and PushNotification implement send() differently. 
Use base class pointers to call send() for different objects.
*/

#include <iostream>
using namespace std;

class Notification {
protected:
    string recipient;
    string message;
public:
    Notification(string rec, string msg) : recipient(rec), message(msg) {}
    
    virtual void send() = 0;  // Pure virtual function
    
    virtual ~Notification() {}  // Virtual destructor
};

class EmailNotification : public Notification {
private:
    string subject;
public:
    EmailNotification(string rec, string msg, string sub) 
        : Notification(rec, msg), subject(sub) {}
    
    void send() override {
        cout << "EMAIL SENT" << endl;
        cout << "To: " << recipient << endl;
        cout << "Subject: " << subject << endl;
        cout << "Message: " << message << endl;
        cout << "Delivered via SMTP server" << endl;
    }
};

class SMSNotification : public Notification {
public:
    SMSNotification(string rec, string msg) : Notification(rec, msg) {}
    
    void send() override {
        cout << "SMS SENT" << endl;
        cout << "To: " << recipient << endl;
        cout << "Message: " << message << endl;
        cout << "Delivered via cellular network" << endl;
    }
};

class PushNotification : public Notification {
private:
    string appName;
public:
    PushNotification(string rec, string msg, string app) 
        : Notification(rec, msg), appName(app) {}
    
    void send() override {
        cout << "PUSH NOTIFICATION SENT" << endl;
        cout << "User: " << recipient << endl;
        cout << "App: " << appName << endl;
        cout << "Message: " << message << endl;
        cout << "Delivered via push service" << endl;
    }
};

int main() {
    // Using base class pointers for polymorphism
    Notification* notifications[] = {
        new EmailNotification("john@email.com", "Welcome to our service!", "Welcome"),
        new SMSNotification("+1234567890", "Your OTP is 123456"),
        new PushNotification("user123", "You have a new message", "ChatApp")
    };
    
    cout << "Sending notifications:\n\n";
    
    for (int i = 0; i < 3; i++) {
        notifications[i]->send();
        cout << "\n";
    }
    
    // Clean up memory
    for (int i = 0; i < 3; i++) {
        delete notifications[i];
    }
    
    return 0;
}
