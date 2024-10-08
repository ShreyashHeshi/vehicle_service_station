#include "../include/oil.h"

Oil::Oil()
{
}

Oil::Oil(double cost)
{
    this->cost = cost;
}
void Oil::input()
{
    Service::input();
    cout << "Enter oil cost" << endl;
    cin >> cost;
}
void Oil::display()
{
    cout << left << setw(50) << " \t\t Oil name ";
    cout << " = " << get_desc() << endl;
    cout << left << setw(50) << " \t\t Oil cost ";
    cout << " = " << cost << endl;
    // cout << "\t\t\t\tOil name     = " << setw(30) << right << get_desc() << endl;
    // cout << "\t\t\t\tOil cost     = " << setw(30) << right << cost << endl;
}
double Oil::get_cost()
{
    return cost;
}
void Oil::set_cost()
{
    this->cost = cost;
}
double Oil::price()
{

    return cost;
}