#ifndef SERVICE_H
#define SERVICE_H
#include <iomanip>
#include <iostream>
using namespace std;

class Service
{
private:
    string desc;

public:
    Service();

    Service(string desc);
    virtual void input();
    virtual void display();
    string get_desc();
    void set_desc(const string &desc);
    virtual double price() = 0;
};

#endif