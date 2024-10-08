#ifndef PART_H
#define PART_H
#include <iomanip>
#include <iostream>
using namespace std;

class Part
{
private:
    string desc;
    double rate;

public:
    Part();
    Part(string desc, double rate);

    void acceptPart();

    void display();

    string get_desc();

    double get_rate();

    void set_desc(const string desc);

    void set_rate(double rate);
};

#endif