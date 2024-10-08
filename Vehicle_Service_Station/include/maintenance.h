#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include <iomanip>
#include <iostream>
#include <list>
using namespace std;
#include "../include/part.h"
#include "../include/service.h"

class Maintenance : public Service
{
private:
    double labour_charges;
    list<Part> part_list;

public:
    Maintenance();
    Maintenance(string &desc, double labour_charges);
    void input();
    void display();
    double get_labour_charges();
    list<Part> &get_part_list();
    void set_labour_charges();
    double price();
    void add_part();
};

#endif