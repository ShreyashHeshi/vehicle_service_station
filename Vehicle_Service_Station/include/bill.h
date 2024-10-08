#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;
#include "../include/service_request.h"

class Bill
{
private:
    Service_request *serviceRequest;
    double amount;
    double paid_amount;

public:
    Bill();
    Bill(Service_request *serviceRequest);
    void acceptBill();
    double compute_amount();
    double compute_tax();
    double compute_total_bill();
    double get_amount();
    double get_paid_amount();
    void set_paid_amount(double amount);
    void display();
};

#endif