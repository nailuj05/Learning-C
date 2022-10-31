#include <iostream>

int main()
{
    const float PI = 3.141;

    int num = 15;
    double floatNum = 5.99;
    char letter = 'A';
    std::string text = "Hello World"; // String is part of std
    bool boolean = true;

    std::cout << "Int: " << num << std::endl; // Endl aswell
    std::cout << "Double: " << floatNum << std::endl;
    std::cout << "Char: " << letter << std::endl;
    std::cout << "String: " << text << std::endl;
    std::cout << "Bool: " << boolean << std::endl; // Bool just outputs 0/1

    std::cout << "PI is constant, it has a value of " << PI << std::endl;
    return 0;
}