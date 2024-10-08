#include "../include/bill.h"

Bill::Bill()
{
}

Bill::Bill(Service_request *serviceRequest)
{
    this->serviceRequest = serviceRequest;
    paid_amount = 0;
}
void Bill::acceptBill()
{
    cout << "your bill amount = " << amount << endl;

    cout << "Enter your paid amount" << endl;
    cin >> paid_amount;
    ofstream fout("../data/bill.txt", ios::app);
    fout << amount << "," << paid_amount << ',' << serviceRequest->get_cust_name() << ',' << serviceRequest->get_veh_number() << endl;
    fout.close();
}
double Bill::compute_amount()
{

    double cost = 0;
    for (Service *s : serviceRequest->get_serv_list())
    {

        cost = s->price() + cost;
    }
    amount = cost;
    return amount;
}
double Bill::compute_tax()
{
    return compute_amount() * 0.18;
}
double Bill::compute_total_bill()
{
    amount = compute_amount() + compute_tax();
    return amount;
}
double Bill::get_amount()
{
    return amount;
}
double Bill::get_paid_amount()
{
    return paid_amount;
}
void Bill::set_paid_amount(double amount)
{
    this->paid_amount = paid_amount;
}
void Bill::display()
{

    // for (list<Service *>::iterator it = serviceRequest->get_serv_list().begin(); it != serviceRequest->get_serv_list().end(); it++)
    // {
    //     (**it).display();  //it traversal pointer acts as object while calling abstract service class display.
    //}
    cout << "*******************************************************************************************************" << endl;
    cout << " \t\t\t\t Gajanan Service Station" << endl;
    cout << "*******************************************************************************************************" << endl;
    for (Service *s : serviceRequest->get_serv_list())
    {
        s->display();
    }
    cout << "*******************************************************************************************************" << endl;
    cout << left << setw(50) << " \t\t bill amount ";
    cout << " = " << compute_amount() << endl;
    cout << left << setw(50) << " \t\t tax amount(18%) ";
    cout << " = " << compute_tax() << endl;
    cout << left << setw(50) << " \t\t total amount to pay ";
    cout << " = " << compute_total_bill() << endl;
    cout << left << setw(50) << " \t\t paid amount ";
    cout << " = " << paid_amount << endl;

    // cout << left << setw(70) << " \t\t total amount to pay ";
    // cout << " = " << compute_total_bill() << endl;
}
