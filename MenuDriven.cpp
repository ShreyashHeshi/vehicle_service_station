#include <iostream>
using namespace std;

int menu()
{
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Login" << endl;
    cout << "2. New account" << endl;
    cout << "Enter a chioce" << endl;
    cin >> choice;
    return choice;
}

int subMenu()
{
    int choice;
    cout << "0. Go back" << endl;
    cout << "1. Product list" << endl;
    cout << "2. profile" << endl;
    cout << "Enter a chioce" << endl;
    cin >> choice;
    return choice;
}

void InsideLoginPage()
{
    int choice;
    do
    {
        choice = subMenu();
        switch (choice)
        {
        case 0:
            cout << "Go back" << endl;
            break;
        case 1:
            cout << "Product list" << endl;
            break;
        case 2:
            cout << "profile" << endl;
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
            cout << "Exit" << endl;
            break;
        case 1:
            InsideLoginPage();

            break;
        case 2:
            cout << "create new account" << endl;
            break;
        default:
            cout << "wrong choice" << endl;
        }
    } while (choice != 0);
}

int main()
{
    mainPageOptions();
}
