#include "../include/customer.h"

Customer::Customer()
{
}
Customer::Customer(string name, string address, string mobile)
{
    cout << "Inside parameterised customer constructor" << endl;
    this->name = name;
    this->address = address;
    this->mobile = mobile;
}
void Customer::acceptCustomer()
{
    cout << "Enter your name = " << endl;
    getchar();
    getline(cin, name);
    cout << "Enter your address = " << endl;
    cin >> address;
    cout << "Enter your phone = " << endl;
    cin >> mobile;
}
void Customer::display()
{
    cout << "name = " << name << endl;
    cout << "address = " << address << endl;
    cout << "mobile = " << mobile << endl;
}

string Customer::get_name()
{
    return name;
}
string Customer::get_address()
{
    return address;
}
string Customer::get_mobile()
{
    return mobile;
}
void Customer::set_name(const string &name)
{
    this->name = name;
}
void Customer::set_address(const string &address)
{
    this->address = address;
}
void Customer::set_mobile(const string &mobile)
{
    this->mobile = mobile;
}

vector<Vehicle> &Customer::getVehicleList()
{
    return veh_list;
}

void Customer::displayCustomerVehicles()
{
    for (int i = 0; i < veh_list.size(); i++)
    {
        veh_list[i].display();
    }
}

void Customer::new_vehicle()
{
    Vehicle v;
    v.acceptVehicle();
    veh_list.push_back(v);
    ofstream fout("../data/vehicle.txt", ios::app);
    fout << mobile << "," << v.get_company() << "," << v.get_model() << "," << v.get_number() << endl;
    fout.close();
}

void Customer::load_vehicle()
{
    ifstream fin("../data/vehicle.txt");
    string data;

    while (getline(fin, data))
    {
        stringstream line(data);
        string mobile, company, model, number;
        getline(line, mobile, ',');
        if (this->mobile == mobile)
        {
            getline(line, company, ',');
            getline(line, model, ',');
            getline(line, number, ',');
            veh_list.push_back(Vehicle(company, model, number));
        }
    }
    fin.close();
}
