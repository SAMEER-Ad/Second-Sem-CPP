/*
Question 12: Design a base class Report with a pure virtual method generateReport(). 
Derive PDFReport, ExcelReport, and HTMLReport. Demonstrate calling overridden versions polymorphically.
*/

#include <iostream>
using namespace std;

class Report {
protected:
    string title;
    string data;
public:
    Report(string t, string d) : title(t), data(d) {}
    
    virtual void generateReport() = 0;  // Pure virtual method
    
    virtual ~Report() {}
};

class PDFReport : public Report {
public:
    PDFReport(string t, string d) : Report(t, d) {}
    
    void generateReport() override {
        cout << "=== PDF REPORT ===" << endl;
        cout << "Title: " << title << endl;
        cout << "Format: PDF Document" << endl;
        cout << "Content: " << data << endl;
        cout << "Features: Portable, Print-ready, Secure" << endl;
        cout << "Generated PDF successfully!" << endl;
    }
};

class ExcelReport : public Report {
public:
    ExcelReport(string t, string d) : Report(t, d) {}
    
    void generateReport() override {
        cout << "=== EXCEL REPORT ===" << endl;
        cout << "Title: " << title << endl;
        cout << "Format: Excel Spreadsheet (.xlsx)" << endl;
        cout << "Content: " << data << endl;
        cout << "Features: Calculations, Charts, Filters" << endl;
        cout << "Generated Excel file successfully!" << endl;
    }
};

class HTMLReport : public Report {
public:
    HTMLReport(string t, string d) : Report(t, d) {}
    
    void generateReport() override {
        cout << "=== HTML REPORT ===" << endl;
        cout << "<html><head><title>" << title << "</title></head>" << endl;
        cout << "<body><h1>" << title << "</h1>" << endl;
        cout << "<p>" << data << "</p>" << endl;
        cout << "</body></html>" << endl;
        cout << "Features: Web-compatible, Interactive, Responsive" << endl;
        cout << "Generated HTML report successfully!" << endl;
    }
};

// Function to demonstrate polymorphism
void processReport(Report* report) {
    report->generateReport();
}

int main() {
    string reportData = "Sales increased by 15% this quarter. Revenue: $250,000";
    
    // Create different report objects
    PDFReport pdf("Q3 Sales Report", reportData);
    ExcelReport excel("Q3 Sales Report", reportData);
    HTMLReport html("Q3 Sales Report", reportData);
    
    cout << "Generating reports polymorphically:\n\n";
    
    // Polymorphic calls using base class pointer
    Report* reports[] = {&pdf, &excel, &html};
    
    for (int i = 0; i < 3; i++) {
        processReport(reports[i]);
        cout << "\n";
    }
    
    return 0;
}
