/*
Question 1: Create a BankAccount base class with methods to deposit(), withdraw() and displayBalance(). 
Derive SavingsAccount and CurrentAccount classes with their own rules for minimum balance and overdraft limit.
*/

#include <iostream>
using namespace std;

class BankAccount {
protected:
    double bal;
    string accNo;
public:
    BankAccount(string acc, double b = 0) : accNo(acc), bal(b) {}
    
    virtual void deposit(double amt) {
        if(amt > 0) {
            bal += amt;
            cout << "Deposited: $" << amt << endl;
        }
    }
    
    virtual bool withdraw(double amt) {
        if(amt > 0 && amt <= bal) {
            bal -= amt;
            cout << "Withdrawn: $" << amt << endl;
            return true;
        }
        cout << "Insufficient balance!" << endl;
        return false;
    }
    
    void displayBalance() {
        cout << "Account: " << accNo << ", Balance: $" << bal << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double minBal = 500;
public:
    SavingsAccount(string acc, double b = 500) : BankAccount(acc, b) {}
    
    bool withdraw(double amt) override {
        if(amt > 0 && (bal - amt) >= minBal) {
            bal -= amt;
            cout << "Withdrawn: $" << amt << endl;
            return true;
        }
        cout << "Cannot withdraw! Minimum balance $" << minBal << " required." << endl;
        return false;
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit = 1000;
public:
    CurrentAccount(string acc, double b = 0) : BankAccount(acc, b) {}
    
    bool withdraw(double amt) override {
        if(amt > 0 && (bal - amt) >= -overdraftLimit) {
            bal -= amt;
            cout << "Withdrawn: $" << amt << endl;
            return true;
        }
        cout << "Overdraft limit $" << overdraftLimit << " exceeded!" << endl;
        return false;
    }
};

int main() {
    SavingsAccount s("SAV001", 1000);
    CurrentAccount c("CUR001", 200);
    
    s.displayBalance();
    s.withdraw(600);  // Should fail
    s.withdraw(400);  // Success
    s.displayBalance();
    
    cout << "\n";
    
    c.displayBalance();
    c.withdraw(800);  // Success (overdraft)
    c.displayBalance();
    c.withdraw(500);  // Should fail
    
    return 0;
}
