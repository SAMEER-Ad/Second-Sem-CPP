/*
Question 5: Create a product inventory system. Base class Product and derived classes PerishableProduct 
(with expiry date) and ElectronicProduct (with warranty info). Override a displayDetails() method.
*/

#include <iostream>
using namespace std;

class Product {
protected:
    string id;
    string name;
    double price;
    int stock;
public:
    Product(string i, string n, double p, int s) : id(i), name(n), price(p), stock(s) {}
    
    virtual void displayDetails() {
        cout << "ID: " << id << ", Name: " << name 
             << ", Price: $" << price << ", Stock: " << stock;
    }
    
    void updateStock(int qty) {
        stock += qty;
    }
};

class PerishableProduct : public Product {
private:
    string expiryDate;
public:
    PerishableProduct(string i, string n, double p, int s, string exp) 
        : Product(i, n, p, s), expiryDate(exp) {}
    
    void displayDetails() override {
        Product::displayDetails();
        cout << ", Expiry: " << expiryDate << " [PERISHABLE]" << endl;
    }
    
    bool isExpired(string currentDate) {
        // Simple comparison (assumes YYYY-MM-DD format)
        return currentDate > expiryDate;
    }
};

class ElectronicProduct : public Product {
private:
    int warrantyMonths;
    string brand;
public:
    ElectronicProduct(string i, string n, double p, int s, int w, string b) 
        : Product(i, n, p, s), warrantyMonths(w), brand(b) {}
    
    void displayDetails() override {
        Product::displayDetails();
        cout << ", Brand: " << brand << ", Warranty: " << warrantyMonths << " months [ELECTRONIC]" << endl;
    }
    
    void extendWarranty(int months) {
        warrantyMonths += months;
        cout << "Warranty extended by " << months << " months" << endl;
    }
};

int main() {
    PerishableProduct p1("P001", "Milk", 3.50, 50, "2025-08-01");
    PerishableProduct p2("P002", "Bread", 2.00, 30, "2025-07-28");
    ElectronicProduct e1("E001", "Laptop", 1200.00, 10, 24, "Dell");
    ElectronicProduct e2("E002", "Phone", 800.00, 25, 12, "Samsung");
    
    cout << "Product Inventory:\n";
    p1.displayDetails();
    p2.displayDetails();
    e1.displayDetails();
    e2.displayDetails();
    
    cout << "\nChecking expiry:\n";
    cout << "Milk expired? " << (p1.isExpired("2025-07-26") ? "Yes" : "No") << endl;
    cout << "Bread expired? " << (p2.isExpired("2025-07-29") ? "Yes" : "No") << endl;
    
    return 0;
}
