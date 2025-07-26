/*
Question 13: Create a payment system where PaymentMethod is an abstract class with method processPayment(). 
Implement CreditCard, UPI, and Cash as derived classes. Demonstrate polymorphic payment processing.
*/

#include <iostream>
using namespace std;

class PaymentMethod {
protected:
    double amount;
    string transactionId;
public:
    PaymentMethod(double amt) : amount(amt) {
        transactionId = "TXN" + to_string(rand() % 10000);
    }
    
    virtual bool processPayment() = 0;  // Pure virtual method
    
    virtual void showReceipt() {
        cout << "Transaction ID: " << transactionId << endl;
        cout << "Amount: $" << amount << endl;
    }
    
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
    string holderName;
public:
    CreditCard(double amt, string card, string name) 
        : PaymentMethod(amt), cardNumber(card), holderName(name) {}
    
    bool processPayment() override {
        cout << "Processing Credit Card Payment..." << endl;
        cout << "Card: ****" << cardNumber.substr(cardNumber.length()-4) << endl;
        cout << "Holder: " << holderName << endl;
        
        // Simulate processing
        if (amount <= 10000) {  // Credit limit check
            cout << "Payment successful via Credit Card!" << endl;
            showReceipt();
            return true;
        } else {
            cout << "Payment failed: Credit limit exceeded!" << endl;
            return false;
        }
    }
};

class UPI : public PaymentMethod {
private:
    string upiId;
public:
    UPI(double amt, string id) : PaymentMethod(amt), upiId(id) {}
    
    bool processPayment() override {
        cout << "Processing UPI Payment..." << endl;
        cout << "UPI ID: " << upiId << endl;
        
        // Simulate processing
        cout << "Connecting to UPI servers..." << endl;
        cout << "Payment successful via UPI!" << endl;
        showReceipt();
        return true;
    }
};

class Cash : public PaymentMethod {
private:
    double cashGiven;
public:
    Cash(double amt, double given) : PaymentMethod(amt), cashGiven(given) {}
    
    bool processPayment() override {
        cout << "Processing Cash Payment..." << endl;
        cout << "Amount due: $" << amount << endl;
        cout << "Cash given: $" << cashGiven << endl;
        
        if (cashGiven >= amount) {
            double change = cashGiven - amount;
            cout << "Payment successful via Cash!" << endl;
            if (change > 0) {
                cout << "Change to return: $" << change << endl;
            }
            showReceipt();
            return true;
        } else {
            cout << "Payment failed: Insufficient cash!" << endl;
            return false;
        }
    }
};

// Function to process any payment method polymorphically
void processTransaction(PaymentMethod* payment) {
    cout << "========================================" << endl;
    if (payment->processPayment()) {
        cout << "Transaction completed successfully!" << endl;
    } else {
        cout << "Transaction failed!" << endl;
    }
    cout << "========================================\n" << endl;
}

int main() {
    // Different payment methods
    CreditCard cc(150.00, "1234567890123456", "John Doe");
    UPI upi(75.50, "john@paytm");
    Cash cash(25.00, 30.00);
    
    cout << "Payment Processing System\n" << endl;
    
    // Polymorphic payment processing
    PaymentMethod* payments[] = {&cc, &upi, &cash};
    
    for (int i = 0; i < 3; i++) {
        processTransaction(payments[i]);
    }
    
    return 0;
}
