#include <iostream>
#include <string>
#include <limits>  
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    void acceptPersonDetails() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayPersonDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int empID;
    string department;

public:
    Employee(string n = "", int a = 0, int id = 0, string dept = "")
        : Person(n, a), empID(id), department(dept) {}

    void acceptEmployeeDetails() {
        acceptPersonDetails();
        
        cout << "Enter Employee ID: ";
        while (!(cin >> empID)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number for ID: ";
        }
        cin.ignore();
        
        cout << "Enter Department: ";
        getline(cin, department);
    }

    void displayEmployeeDetails() {
        displayPersonDetails();
        cout << "Employee ID: " << empID << ", Department: " << department << endl;
    }
};

class Manager : public Employee {
private:
    string project;

public:
    Manager(string n = "", int a = 0, int id = 0, string dept = "", string proj = "")
        : Employee(n, a, id, dept), project(proj) {}

    void acceptManagerDetails() {
        acceptEmployeeDetails();
        cout << "Enter Project Assigned: ";
        getline(cin, project);
    }

    void displayManagerDetails() {
        displayEmployeeDetails();
        cout << "Project Assigned: " << project << endl;
    }
};

int main() {
    const int SIZE = 2;
    Manager managers[SIZE];

    cout << "Enter details for " << SIZE << " managers:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nManager " << i + 1 << ":\n";
        managers[i].acceptManagerDetails();
    }

    cout << "\nManager Details:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\nManager " << i + 1 << ":\n";
        managers[i].displayManagerDetails();
    }

    return 0;
}
