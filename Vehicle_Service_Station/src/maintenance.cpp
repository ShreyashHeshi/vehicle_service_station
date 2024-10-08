#include "../include/maintenance.h"

Maintenance::Maintenance()
{
}
Maintenance::Maintenance(string &desc, double labour_charges)
{
    this->labour_charges = labour_charges;
}
void Maintenance::input()
{
    Service::input();
    cout << "Enter your labour charges" << endl;
    cin >> labour_charges;
}
void Maintenance::display()
{
    Service::display();
    cout << left << setw(50) << " \t\t labour charge = ";
    cout << " = " << labour_charges << endl;
    // cout << "\t\t\t\tlabour charge   = " << setw(30) << labour_charges << endl;
    for (list<Part>::iterator it = part_list.begin(); it != part_list.end(); it++)
    {
        it->display();
    }
}
double Maintenance::get_labour_charges()
{
    return labour_charges;
}
list<Part> &Maintenance::get_part_list()
{
    return part_list;
}
void Maintenance::set_labour_charges()
{
    this->labour_charges = labour_charges;
}
void Maintenance::add_part()
{
    int choice;
    do
    {
        Part p;
        p.acceptPart();
        part_list.push_back(p);
        cout << "do you wish to add any more parts" << endl;
        cout << "press 0 to exit or any number to add part" << endl;
        cin >> choice;

    } while (choice != 0);
}

double Maintenance::price()
{
    Part p;
    double total_cost_part = 0;
    for (Part p : part_list)
    {
        total_cost_part = p.get_rate() + total_cost_part;
    }
    total_cost_part = total_cost_part + labour_charges;
    return total_cost_part;
}
