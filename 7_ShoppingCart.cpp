/*
Question 7: Build an online shopping cart: base class Item with price, ID, name. 
Subclasses Book, Clothing, and ElectronicItem apply different discount rules via overridden getFinalPrice() method.
*/

#include <iostream>
using namespace std;

class Item {
protected:
    string id;
    string name;
    double price;
public:
    Item(string i, string n, double p) : id(i), name(n), price(p) {}
    
    virtual double getFinalPrice() {
        return price;  // No discount by default
    }
    
    virtual void displayItem() {
        cout << "ID: " << id << ", Name: " << name 
             << ", Original: $" << price << ", Final: $" << getFinalPrice() << endl;
    }
};

class Book : public Item {
private:
    string author;
public:
    Book(string i, string n, double p, string a) : Item(i, n, p), author(a) {}
    
    double getFinalPrice() override {
        // Books get 10% discount
        return price * 0.9;
    }
    
    void displayItem() override {
        cout << "BOOK - ";
        Item::displayItem();
        cout << "Author: " << author << " (10% discount applied)" << endl;
    }
};

class Clothing : public Item {
private:
    string size;
public:
    Clothing(string i, string n, double p, string s) : Item(i, n, p), size(s) {}
    
    double getFinalPrice() override {
        // Clothing gets 15% discount
        return price * 0.85;
    }
    
    void displayItem() override {
        cout << "CLOTHING - ";
        Item::displayItem();
        cout << "Size: " << size << " (15% discount applied)" << endl;
    }
};

class ElectronicItem : public Item {
private:
    string warranty;
public:
    ElectronicItem(string i, string n, double p, string w) : Item(i, n, p), warranty(w) {}
    
    double getFinalPrice() override {
        // Electronics get 5% discount
        return price * 0.95;
    }
    
    void displayItem() override {
        cout << "ELECTRONIC - ";
        Item::displayItem();
        cout << "Warranty: " << warranty << " (5% discount applied)" << endl;
    }
};

int main() {
    Book b("B001", "C++ Programming", 50.00, "Bjarne Stroustrup");
    Clothing c("C001", "T-Shirt", 25.00, "Medium");
    ElectronicItem e("E001", "Headphones", 100.00, "1 year");
    
    cout << "Shopping Cart Items:\n";
    b.displayItem();
    cout << "\n";
    c.displayItem();
    cout << "\n";
    e.displayItem();
    
    double total = b.getFinalPrice() + c.getFinalPrice() + e.getFinalPrice();
    cout << "\nTotal Cart Value: $" << total << endl;
    
    return 0;
}
