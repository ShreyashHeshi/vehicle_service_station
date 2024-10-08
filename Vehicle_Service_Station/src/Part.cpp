
#include <iostream>
using namespace std;
#include "../include/part.h"
Part::Part()
{
}
Part::Part(string desc, double rate)
{
    cout << "Inside parametrised part constructor" << endl;
    this->desc = desc;
    this->rate = rate;
}
void Part::acceptPart()
{
    cout << "Enter your vehicle part name = " << endl;
    getchar();
    getline(cin, desc);
    cout << "Enter part rate" << endl;
    cin >> rate;
}
void Part::display()
{
    cout << left << setw(50) << " \t\t part description ";
    cout << " = " << desc << endl;
    cout << left << setw(50) << " \t\t part rate ";
    cout << " = " << rate << endl;
    // cout << "\t\t\t\tpart description = " << setw(30) << right << desc << endl;
    // cout << "\t\t\t\tpart rate = " << setw(30) << right << rate << endl;
}
string Part::get_desc()
{
    return desc;
}
double Part::get_rate()
{
    return rate;
}
void Part::set_desc(const string desc)
{
    this->desc = desc;
}
void Part::set_rate(double rate)
{
    this->rate = rate;
}
