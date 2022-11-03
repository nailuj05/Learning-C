#include <iostream>

using namespace std;

class Animal
{
public:
    void makeSound()
    {
        cout << "The Animale makes a sound.\n";
    }
};

class Pig : public Animal
{
public:
    void makeSound()
    {
        cout << "Oink Oink\n";
    }
};

class Dog : public Animal
{
public:
    void makeSound()
    {
        cout << "Woof woof\n";
    }
};

int main()
{
    Animal animal;
    animal.makeSound();

    Pig pig;
    pig.makeSound();

    Dog dog;
    dog.makeSound();

    return 0;
}