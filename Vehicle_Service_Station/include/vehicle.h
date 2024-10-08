#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle
{
private:
    string company;
    string model;
    string number;

public:
    Vehicle();
    Vehicle(const string &company, const string &model, const string &number);

    void acceptVehicle();

    void display();

    string get_company();

    string get_model();

    string get_number();

    void set_company(const string &company);

    void set_model(const string &model);

    void set_number(const string);
};

#endif