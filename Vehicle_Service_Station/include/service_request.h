#ifndef SERVICE_REQUEST_H
#define SERVICE_REQUEST_H

#include <iostream>
#include <list>
using namespace std;
#include "../include/service.h"

class Service_request
{
private:
    string cust_name;
    list<Service *> serv_list; // association has-a relationship
    string veh_number;

public:
    Service_request();
    Service_request(string cust_name, string veh_number);
    string get_cust_name();
    string get_veh_number();
    list<Service *> &get_serv_list();
    void set_cust_name(const string &cust_name);
    void set_veh_number(const string &veh_number);
    void add_item(Service *serv);
    void process_request();
};

#endif