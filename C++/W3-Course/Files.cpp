#include <iostream>
#include <fstream>

using namespace std;

void CreateAndWriteFile(string);
string ReadFile();

int main()
{
    CreateAndWriteFile("Hello there!\nMaster Yoda?!");

    cout << ReadFile() << endl;

    return 0;
}

void CreateAndWriteFile(string text)
{
    ofstream wFile("files/test.txt");

    wFile << text;

    wFile.close();
}

string ReadFile()
{
    string line, fileText;

    ifstream rFile("files/test.txt");

    while (getline(rFile, line))
    {
        fileText += line + "\n";
    }

    rFile.close();

    return fileText;
}