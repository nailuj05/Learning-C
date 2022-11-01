#include <iostream>

using namespace std;

int main()
{
    string cars[3];

    string planes[4] = {"F-35", "F-16", "F-18", "A-10"};

    int nums[] = {10, 20, 30};

    cout << planes[2] << endl;

    planes[3] = "F/A-18";

    cout << planes[3] << endl;

    for (int i = 0; i < 4; i++)
    {
        cout << planes[i] << endl;
    }

    for (int n : nums)
    {
        cout << n << endl;
    }

    // Size in bytes
    cout << sizeof(nums) << endl;

    // Size of array
    cout << (sizeof(nums) / sizeof(int)) << endl;

    // Multi-Dimensional Arrays
    string letters[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}};

    cout << letters[1][3] << endl;

    return 0;
}