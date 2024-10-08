#include "../include/service.h"

Service::Service()
{
}
Service::Service(string desc)
{
    this->desc = desc;
}
void Service::input()
{
    cout << "Enter your Vehicle maintenance/ Repairing / Oil change" << endl;
    getchar();
    getline(cin, desc);
}
void Service::display()
{
    cout << left << setw(50) << " \t\t description done ";
    cout << " = " << desc << endl;
}
string Service::get_desc()
{
    return desc;
}

void Service::set_desc(const string &desc)
{
    this->desc = desc;
}
