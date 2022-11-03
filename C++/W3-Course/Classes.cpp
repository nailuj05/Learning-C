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

class F35 : public Plane
{
public:
    float thrustAngle = 0;

    F35(string x, int n) : Plane(x, n)
    {
        type = x;
        number = n;
    }
};

int main()
{
    Plane plane("F/A-18", 3);
    plane.Shoot();
    plane.SetMissile("Fox-2");
    plane.Shoot();

    F35 f35("F-35B", 2);
    f35.Shoot();
    f35.thrustAngle = 90;

    return 0;
}