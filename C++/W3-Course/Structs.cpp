#include <iostream>

using namespace std;

struct Position
{
    int x;
    int y;
};

int main()
{
    struct
    {
        int num;
        string string;
    } testStruct, testStruct2;

    testStruct.num = 420;
    testStruct.string = "LOL";

    cout << testStruct.num << endl;
    cout << testStruct.string << endl;

    Position pos1;
    pos1.x = 1;
    pos1.y = 2;

    cout << "Position: [" << pos1.x << "|" << pos1.y << "]\n";

    return 0;
}