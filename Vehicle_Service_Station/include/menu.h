#ifndef MENU_H
#define MENU_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;
#include "../include/service_request.h"
#include "../include/customer.h"
#include "../include/service_station.h"
#include "../include/vehicle.h"
#include "../include/maintenance.h"
#include "../include/oil.h"
#include "../include/service.h"
#include "../include/bill.h"

enum subMenu
{
    GOBACK,
    EXITSTING_CUSTOMER,
    DISPLAY_VEHICLES,
    SELECT_VEHICLES,
    PROCESS_REQUEST,
    DISPLAY_BILL,
    GET_BILL
};

void InsideServiveRequest();
void mainPageOptions();
string InsideVehiclePage(Customer *cptr);
void InsideProcessRequest(Service_request *serviceRequest);
int menu();
int submenu();
int vehicleDetails();
int processDetails();
void displayAllCustomers();
void find_customer();
void exe_customer(Customer **cptr);
void load_customer();
void new_customer();
// void choose_vehicle();

#endif