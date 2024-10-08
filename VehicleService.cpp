#include <iostream>
using namespace std;

class Employee
{
private:
    int empid;
    string name;
    double salary;

public:
    Employee()
    {
    }
    Employee(int empid, string name, double salary)
    {
        cout << "Enter empid" << endl;
        cin >> empid;
        cout << "ENter your name" << endl;
        cin >> name;
        cout << "Enter salary" << endl;
        cin >> salary;
    }

    void display()
    {
        cout << "empid is " << empid << endl;
        cout << "name is " << name << endl;
        cout << "salary is" << salary << endl;
    }
};

int main()
{
    // Employee e1;
    Employee(21, "Shreyash", 99999);
}