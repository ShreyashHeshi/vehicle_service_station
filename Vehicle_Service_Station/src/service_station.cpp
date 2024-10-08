#include "../include/service_station.h"

Service_station ::Service_station()
{
}
Service_station ::Service_station(string name)
{
    this->name = name;
    this->bill_list = bill_list;
    this->cust_list = cust_list;
}

void Service_station::acceptCustomerDetails()
{
    cout << "Enter customer name" << endl;
    cin >> name;
}
void Service_station::display()
{
}
string Service_station::Name_is()
{
    return name;
}
void Service_station::name_set(const string &name)
{
    this->name = name;
}
list<Bill> &Service_station::get_bill_list()
{
    return bill_list;
}
list<Customer> &Service_station::get_cust_list()
{
    return cust_list;
}

void Service_station::total_bill()
{
    ifstream fin("../data/bill.txt");
    string data;
    double total_amount = 0;
    double total_paid_bill = 0;
    string name, totalBill, paidBill;
    while (getline(fin, data))
    {
        stringstream line(data);

        getline(line, totalBill, ',');
        getline(line, paidBill, ',');
        total_amount = total_amount + stod(totalBill);
        total_paid_bill = total_paid_bill + stod(paidBill);
        // bill_list.push_back(Bill(totalBill, paidBill));
    }
    fin.close();
    cout << "total bill = " << total_amount << endl;
    cout << "total paid amount = " << total_paid_bill << endl;
}