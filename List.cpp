#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);

    cout << "size of list = " << l1.size() << endl;
    l1.push_back(40);
    l1.push_back(50);
    cout << "size of list = " << l1.size() << endl;

    for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
    {
        cout << "data = " << *it << endl;
    }

    return 0;
}