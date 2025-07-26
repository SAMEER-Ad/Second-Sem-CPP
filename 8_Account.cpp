/*
Question 8: Implement a class Account with balance and transaction history. 
Derive DigitalWallet and CreditCardAccount. Override withdraw() to show transaction fees or interest.
*/

#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
    string accNo;
    double balance;
    vector<string> transactions;
public:
    Account(string acc, double bal = 0) : accNo(acc), balance(bal) {}
    
    virtual void deposit(double amt) {
        balance += amt;
        transactions.push_back("Deposit: +$" + to_string(amt));
        cout << "Deposited $" << amt << endl;
    }
    
    virtual bool withdraw(double amt) {
        if (amt <= balance) {
            balance -= amt;
            transactions.push_back("Withdraw: -$" + to_string(amt));
            cout << "Withdrawn $" << amt << endl;
            return true;
        }
        cout << "Insufficient balance!" << endl;
        return false;
    }
    
    void showBalance() {
        cout << "Account: " << accNo << ", Balance: $" << balance << endl;
    }
    
    void showTransactions() {
        cout << "Transaction History for " << accNo << ":" << endl;
        for(const string& t : transactions) {
            cout << "- " << t << endl;
        }
    }
};

class DigitalWallet : public Account {
private:
    double transactionFee = 0.5;  // $0.50 per transaction
public:
    DigitalWallet(string acc, double bal = 0) : Account(acc, bal) {}
    
    bool withdraw(double amt) override {
        double totalDeduction = amt + transactionFee;
        if (totalDeduction <= balance) {
            balance -= totalDeduction;
            transactions.push_back("Withdraw: -$" + to_string(amt) + " (Fee: $" + to_string(transactionFee) + ")");
            cout << "Withdrawn $" << amt << " (Transaction fee: $" << transactionFee << ")" << endl;
            return true;
        }
        cout << "Insufficient balance for withdrawal + fee!" << endl;
        return false;
    }
};

class CreditCardAccount : public Account {
private:
    double creditLimit = 5000;
    double interestRate = 0.02;  // 2% monthly interest
public:
    CreditCardAccount(string acc, double bal = 0) : Account(acc, bal) {}
    
    bool withdraw(double amt) override {
        if (balance - amt >= -creditLimit) {
            balance -= amt;
            if (balance < 0) {
                double interest = abs(balance) * interestRate;
                balance -= interest;
                transactions.push_back("Withdraw: -$" + to_string(amt) + " (Interest: $" + to_string(interest) + ")");
                cout << "Withdrawn $" << amt << " (Interest charged: $" << interest << ")" << endl;
            } else {
                transactions.push_back("Withdraw: -$" + to_string(amt));
                cout << "Withdrawn $" << amt << endl;
            }
            return true;
        }
        cout << "Credit limit exceeded!" << endl;
        return false;
    }
};

int main() {
    DigitalWallet dw("DW001", 100);
    CreditCardAccount cc("CC001", 200);
    
    cout << "=== Digital Wallet ===\n";
    dw.showBalance();
    dw.withdraw(50);
    dw.showBalance();
    dw.showTransactions();
    
    cout << "\n=== Credit Card ===\n";
    cc.showBalance();
    cc.withdraw(250);  // Goes negative
    cc.showBalance();
    cc.showTransactions();
    
    return 0;
}
