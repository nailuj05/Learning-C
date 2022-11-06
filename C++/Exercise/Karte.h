#include <iostream>

class Karte
{
public:
    std::string front;
    std::string back;

    Karte(std::string f, std::string b)
    {
        front = f;
        back = b;
    }

    std::string Read()
    {
        return "[" + front + "|" + back + "]";
    }
};