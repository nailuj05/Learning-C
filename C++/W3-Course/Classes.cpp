#include <iostream>

using namespace std;

// Create class
class Plane
{
public:
    string type;
    int number;

    Plane(string x, int n)
    {
        type = x;
        number = n;
    }

    void Shoot()
    {
        cout << Missile << endl;
    }

    void SetMissile(string);

private:
    string Missile = "Fox-3";
};

// Define function outside of Class
void Plane::SetMissile(string type)
{
    Missile = type;
}

int main()
{
    Plane plane("F/A", 18);
    plane.Shoot();
    plane.SetMissile("Fox-2");
    plane.Shoot();

    return 0;
}