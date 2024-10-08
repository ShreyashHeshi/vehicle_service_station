#include "../include/vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle()
{
}
Vehicle::Vehicle(const string &company, const string &model, const string &number)
{
    this->company = company;
    this->model = model;
    this->number = number;
}
void Vehicle::acceptVehicle()
{
    cout << "Enter vehicle company" << endl;
    cin >> company;
    cout << "Enter vehicle model" << endl;
    cin >> model;
    cout << "Enter vehicle number" << endl;
    cin >> number;
}
void Vehicle::display()
{
    cout << "Vehicle company = " << company << endl;
    cout << "Vehicle model = " << model << endl;
    cout << "Vehicle number = " << number << endl;
}
string Vehicle::get_company()
{
    return company;
}
string Vehicle::get_model() 
{
    return model;
}
string Vehicle::get_number()
{
    return number;
}
void Vehicle::set_company(const string &company)
{
    this->company = company;
}
void Vehicle::set_model(const string &model)
{
    this->model = model;
}
void Vehicle::set_number(const string)
{
    this->number = number;
}
