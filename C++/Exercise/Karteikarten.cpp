#include <iostream>
#include <fstream>
#include "Karte.h"

using namespace std;

template <size_t len>
void Save(Karte (&karten)[len], string path); // Use this to pass the length of the array aswell

int main()
{
    Karte karte1("EU", "European Union");
    Karte karte2("NATO", "North Atlantic Treaty Organization");
    Karte karte3("USA", "United States of America");
    Karte karte4("USSR", "Union of Soviet Socialist Republics");

    Karte karten[] = {karte1, karte2, karte3, karte4};

    Save(karten, "Save.txt");

    return 0;
}

template <size_t len>
void Save(Karte (&karten)[len], string path)
{
    ofstream wFile(path);

    for (Karte k : karten)
    {
        wFile << k.Read() << "\n";
    }

    wFile.close();
}