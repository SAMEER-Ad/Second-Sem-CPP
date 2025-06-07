// 2. Write a class BankAccount that contains details like accountNumber, accountHolderName, and balance. Include methods to deposit, withdraw, and display account details.
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    long accNum;
    string name;
    double balance;

public:
    BankAccount(long acc, string n, double bal) {
        accNum = acc;
        name = n;
        balance = bal;
    }
    
    void deposit(double amt) {
        if (amt > 0) {
            balance += amt;
            cout << "Deposited: $" << amt << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }
    
    void withdraw(double amt) {
        if (amt > 0 && amt <= balance) {
            balance -= amt;
            cout << "Withdrawn: $" << amt << endl;
        } else {
            cout << "Invalid amount or insufficient funds!" << endl;
        }
    }
    
    void display() {
        cout << "Account: " << accNum << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    long acc;
    string name;
    double bal, amt;
    
    cout << "Enter account number: ";
    cin >> acc;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter initial balance: ";
    cin >> bal;
    
    BankAccount account(acc, name, bal);
    
    int choice;
    do {
        cout << "\n1. Deposit 2. Withdraw 3. Display 4. Exit: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amt;
                account.deposit(amt);
                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amt;
                account.withdraw(amt);
                break;
            case 3:
                account.display();
                break;
        }
    } while (choice != 4);
    
    return 0;
}
