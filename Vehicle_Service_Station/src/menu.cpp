#include "../include/menu.h"

Service_station s1;

Vehicle v1;
// Customer *cptr = NULL;

int menu()
{
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. New Customer" << endl;
    cout << "2. New Service request" << endl;
    cout << "3. Today's Business/Total Bill" << endl;
    cout << "4. Total Business" << endl;
    cin >> choice;
    return choice;
}
void new_customer()
{
    Customer c;
    c.acceptCustomer();
    s1.get_cust_list().push_back(c);
    ofstream fout("../data/customer.txt", ios::app);
    fout << c.get_name() << "," << c.get_address() << "," << c.get_mobile() << endl;
    fout.close();
}
void load_customer()
{
    ifstream fin("../data/customer.txt");
    string data;
    while (getline(fin, data))
    {
        string name, phone, address;
        stringstream line(data);
        getline(line, name, ',');
        getline(line, address, ',');
        getline(line, phone, ',');
        s1.get_cust_list().push_back(Customer(name, address, phone));
    }
    fin.close();
}

// void find_customer()
// {
//     string info;
// }

int submenu()
{
    int choice;
    cout << "0. Go back" << endl;
    cout << "1. Existing Customer" << endl;
    cout << "2. Display veicles" << endl;
    cout << "3. Input/choose vehicle" << endl;
    cout << "4. Process Request" << endl;
    cout << "5. Prepare & display bill" << endl;
    cout << "6. Get Payment" << endl;
    cin >> choice;
    return choice;
}

int vehicleDetails()
{
    int choice;
    cout << "0. Back" << endl;
    cout << "1. Choose vehicle" << endl;
    cout << "2. Input vehicle" << endl;
    cin >> choice;
    return choice;
}

int processDetails()
{
    int choice;
    cout << "0. Go back" << endl;
    cout << "1. Maintenance" << endl;
    cout << "2. Repairing" << endl;
    cout << "3. Oil change" << endl;
    cin >> choice;
    return choice;
}

void InsideServiveRequest()
{
    Customer *cptr = NULL;
    string vehnumber = "";
    Service_request *serviceRequest = NULL;
    Bill *bill = NULL;
    int choice;
    do
    {
        choice = submenu();
        switch (choice)
        {
        case GOBACK:
            cout << "Go back" << endl;
            break;
        case EXITSTING_CUSTOMER:
            exe_customer(&cptr);
            if (cptr != NULL)
            {
                cptr->display();
                cptr->load_vehicle();
                cout << "******************************" << endl;
                cout << "Customer found....!!" << endl;
                cout << "******************************" << endl;
            }
            else
            {
                cout << "******************************" << endl;
                cout << "Customer not found" << endl;
                cout << "******************************" << endl;
            }
            break;
        case DISPLAY_VEHICLES:
            if (cptr != NULL)
            {
                cptr->displayCustomerVehicles();
            }
            else
            {
                cout << "******************************" << endl;
                cout << "Select Customer first" << endl;
                cout << "******************************" << endl;
            }
            break;
        case SELECT_VEHICLES:
            if (cptr != NULL)
            {
                cptr->displayCustomerVehicles();
                vehnumber = InsideVehiclePage(cptr);
            }
            else
            {
                cout << "******************************" << endl;
                cout << "Select customer first..!!" << endl;
                cout << "******************************" << endl;
            }
            break;
        case PROCESS_REQUEST:
            if (vehnumber != "")
            {
                serviceRequest = new Service_request(cptr->get_mobile(), vehnumber);
                InsideProcessRequest(serviceRequest);
            }
            else
            {
                cout << "******************************" << endl;
                cout << "Select Vehicle First..!" << endl;
                cout << "******************************" << endl;
            }

            break;
        case DISPLAY_BILL:
            if (serviceRequest != NULL)
            {
                // Bill b(serviceRequest);

                bill = new Bill(serviceRequest);
                bill->display();
            }
            else
            {
                cout << "******************************" << endl;
                cout << "Select Customer and Vehicle First..!" << endl;
                cout << "******************************" << endl;
            }
            break;
        case GET_BILL:
        {
            if (bill != NULL)
            {
                bill->acceptBill();
                s1.get_bill_list().push_back(*bill);
                return;
            }
            else
            {
                cout << "******************************" << endl;
                cout << "preapre bill first....!!" << endl;
                cout << "******************************" << endl;
            }
        }
        break;
        default:
            cout << "wrong choice" << endl;
        }
    } while (choice != 0);
}

void mainPageOptions()
{
    int choice;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 0:
            cout << "Exit...Thank You Visit Again...!!" << endl;
            break;
        case 1:
            new_customer();
            break;
        case 2:
            InsideServiveRequest();
            break;
        case 3:
        {
            double total_amount = 0;
            double total_paid_bill = 0;
            for (list<Bill>::iterator it = s1.get_bill_list().begin(); it != s1.get_bill_list().end(); it++)
            {
                total_amount = total_amount + it->compute_total_bill();
                total_paid_bill = total_paid_bill + it->get_paid_amount();
            }
            cout << "total bill = " << total_amount << endl;
            cout << "total paid amount = " << total_paid_bill << endl;

            break;
        }
        case 4:
            s1.total_bill();
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    } while (choice != 0);
}
string InsideVehiclePage(Customer *cptr)
{
    int choice;
    string vehiclenumber = "";
    do
    {
        choice = vehicleDetails();
        switch (choice)
        {
        case 0:
            cout << "Exit...Thank You for using our app...Visit again" << endl;
            break;
        case 1:
            cptr->displayCustomerVehicles();
            cout << "Enter your vehicle number" << endl;
            cin >> vehiclenumber;
            for (int i = 0; i < cptr->getVehicleList().size(); i++)
            {
                if (vehiclenumber == cptr->getVehicleList()[i].get_number())
                {
                    cptr->getVehicleList()[i].display();
                    cout << "******************************" << endl;
                    cout << "Your Vehicle found..!!" << endl;
                    cout << "******************************" << endl;
                    return vehiclenumber;
                }
            }
            cout << "******************************" << endl;
            cout << "Vehicle not found..!" << endl;
            cout << "******************************" << endl;
            return "";

            break;
        case 2:
            cptr->new_vehicle();
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    } while (choice != 0);
}

void InsideProcessRequest(Service_request *serviceRequest)
{
    int choice;
    Service *service = NULL;
    Maintenance *maintenance = NULL;
    Oil *oil = NULL;
    do
    {
        choice = processDetails();
        switch (choice)
        {
        case 0:
            cout << "Go back" << endl;
            break;
        case 1:
            service = new Maintenance();
            service->input();
            serviceRequest->get_serv_list().push_back(service);
            break;
        case 2:
            service = new Maintenance();
            maintenance = (Maintenance *)service; // downcasting
            maintenance->add_part();
            service->input();
            //  maintenance->display();

            serviceRequest->get_serv_list().push_back(service);
            break;
        case 3:
            service = new Oil();
            service->input();
            serviceRequest->get_serv_list().push_back(service);

            break;
        default:
            cout << "wrong choice" << endl;
        }
    } while (choice != 0);
}

void displayAllCustomers()
{

    for (list<Customer>::iterator it = s1.get_cust_list().begin(); it != s1.get_cust_list().end(); it++)
    {
        // cout << "Data = " << *it << endl;
        it->display();
    }
}

void exe_customer(Customer **cptr)
{
    string Mobile_no;
    cout << "Enter your phone" << endl;
    cin >> Mobile_no;
    for (list<Customer>::iterator it = s1.get_cust_list().begin(); it != s1.get_cust_list().end(); it++)
    {
        if (Mobile_no == it->get_mobile())
        {
            *cptr = &*it;
        }
    }
    // if (*cptr == NULL)
    // {
    //     cout << "******************************" << endl;
    //     cout << "Customer not found" << endl;
    //     cout << "******************************" << endl;
    // }
}

// void choose_vehicle(Customer *cptr)
// {
//     Vehicle *vptr = NULL;
//     if (vptr == NULL)
//         cout << "Add new vehicle first" << endl;
//     else
//         cptr->load_vehicle();
// }

// void displayAllVehicles()
// {

//     for (list<Vehicle>::iterator it = v1.getVehicleList().begin(); it != c1.getVehicleList().end(); it++)
//     {
//         // cout << "Data = " << *it << endl;
//         it->display();
//     }
// }