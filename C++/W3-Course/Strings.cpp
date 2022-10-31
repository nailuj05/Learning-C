#include <iostream>
#include <string> // Do I need it? Runs fine without

using namespace std;

int main()
{
    string firstName = "Joe";
    string lastName = "Mama";
    string fullName = firstName + " " + lastName;

    cout << fullName << endl;

    cout << "The length of the name is: " << fullName.length() << endl; // string.length == string.size

    cout << fullName[0] << endl;

    fullName[0] = 'D';

    cout << fullName << endl;

    // String Input:

    string yourName;
    cout << "Type your full Name: ";
    cin >> yourName; // Will terminate the string after the first whitespace ("Joe Mama" -> "Joe")
    cout << "Your Name is: " << yourName << endl;

    // Better way to do this:

    string yourFullName;
    cout << "Type your full Name again: " << endl;
    cin.clear();
    cin.sync(); // cin only used the previous input to the first whitespace everything after that will be picked up by getline => clear input before (flush input buffer)
    getline(cin, yourFullName);
    cout << "Your Name is: " << yourFullName << endl;

    return 0;
}