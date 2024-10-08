#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
#include "../include/vehicle.h"

class Customer
{
private:
    string name;
    string address;
    string mobile;
    vector<Vehicle> veh_list; // Association Has-a relation

public:
    Customer();
    Customer(string name, string address, string mobile);
    void acceptCustomer();

    void display();

    string get_name();

    string get_address();

    string get_mobile();

    void set_name(const string &name);

    void set_address(const string &address);

    void set_mobile(const string &mobile);
    vector<Vehicle> &getVehicleList();
    void displayCustomerVehicles();
    void new_vehicle();
    void load_vehicle();
    
};

#endif
