#include <iostream>
using namespace std;

enum mainPage
{
    EXIT,
    LOGIN,
    NEWACCOUNT,
};

void InsideLoginPage()
{
    int choice;

    do
    {
        int choice;
        cout << "0. Go back" << endl;
        cout << "1. Product list" << endl;
        cout << "2. profile" << endl;
        cout << "Enter a chioce" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:

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
        int choice;
        cout << "0. Exit" << endl;
        cout << "1. Login" << endl;
        cout << "2. New account" << endl;
        cout << "Enter a chioce" << endl;
        cin >> choice;

        switch (mainPage(choice))
        {
        case EXIT:
            cout << "Exit Thank you for using app" << endl;
            break;
        case LOGIN:
            cout << "Please Login" << endl;
            InsideLoginPage();
            break;
        case NEWACCOUNT:
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
