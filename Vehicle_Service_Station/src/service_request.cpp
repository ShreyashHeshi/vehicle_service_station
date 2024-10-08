#include "../include/service_request.h"

Service_request::Service_request()
{
}
Service_request::Service_request(string cust_name, string veh_number)
{
    this->cust_name = cust_name;
    this->veh_number = veh_number;
}
string Service_request::get_cust_name()
{
    return cust_name;
}
string Service_request::get_veh_number()
{
    return veh_number;
}
list<Service *> &Service_request::get_serv_list()
{
    return serv_list;
}
void Service_request::set_cust_name(const string &cust_name)
{
    this->cust_name = cust_name;
}
void Service_request::set_veh_number(const string &veh_number)
{
    this->veh_number = veh_number;
}
void Service_request::add_item(Service *serv)
{
}
void Service_request::process_request()
{
}