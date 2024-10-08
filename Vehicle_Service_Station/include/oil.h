#ifndef OIL_H
#define OIL_H
#include <iomanip>
#include <iostream>
using namespace std;
#include "../include/service.h"
#include "../include/maintenance.h"

class Oil : public Service
{
private:
    double cost;

public:
    Oil();
    Oil(double cost);
    void input();
    void display();
    double get_cost();
    void set_cost();
    double price();
};

#endif