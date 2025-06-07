// 7. Make a class Book with members title, author, and price. Create a method to check if the book is affordable (i.e., price under a given limit).
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title, author;
    double price;

public:
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }
    
    bool isAffordable(double limit) {
        return price <= limit;
    }
    
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    string title, author;
    double price, limit;
    
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter price: ";
    cin >> price;
    
    Book book(title, author, price);
    
    cout << "\nBook Details:" << endl;
    book.display();
    
    cout << "\nEnter budget limit: ";
    cin >> limit;
    
    if (book.isAffordable(limit)) {
        cout << "Book is affordable!" << endl;
    } else {
        cout << "Book is not affordable!" << endl;
    }
    
    return 0;
}
