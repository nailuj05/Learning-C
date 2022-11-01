#include <iostream>

using namespace std;

int main()
{
    // References
    string food = "Pizza";
    string &meal = food;

    cout << food << endl;
    cout << meal << endl;
    cout << &food << endl;
    cout << &meal << endl;

    // Pointers
    string *ptr = &food;

    cout << ptr << endl;
    cout << *ptr << endl;

    // Modifying
    *ptr = "Hamburger";

    cout << *ptr << endl;
    cout << food << endl;

    return 0;
}