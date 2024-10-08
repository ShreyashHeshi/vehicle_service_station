#ifndef SERVICE_STATION_H
#define SERVICE_STATION_H
#include <fstream>
#include <sstream>
#include <list>
#include <iostream>
using namespace std;

#include "../include/customer.h"
#include "../include/bill.h"

class Service_station
{
private:
    string name;
    list<Bill> bill_list;
    list<Customer> cust_list; // composition tight coupling has-a relation

public:
    Service_station();

    Service_station(string name);

    void acceptCustomerDetails();

    void display();

    string Name_is();

    void name_set(const string &name);

    list<Bill> &get_bill_list();

    list<Customer> &get_cust_list();

    void total_bill();
};

#endif