#include <iostream>
#include <string>
#define PI 3.14159
using namespace std;

class Circle
{
    protected:
        float radius;
    public:
        Circle(float r) : radius(r) {}

        void getradius(float r)
        {
            radius = r;
        }
        float setradius()
        {
            return radius;
        }
        virtual void display() const
        {
            cout << "Circle Details: " << endl;
            cout << "Radius: " << radius << endl;
        }
        float calc1()
        {
            return (2.0 * PI * radius);
        }
        float calc2()
        {
            return (PI * radius* radius);
        }
};
class Cylinder : public Circle
{
    private:
        float height;
    
    public:
        Cylinder(float r, float h) : Circle(r), height(h) {}

        void setheight(float h)
        {
            height = h;
        }
        float getheight()
        {
            return height;
        }
        void display() const override
        {
            cout << "Cylinder Details: " << endl;
            cout << "Radius: " << radius << endl;
            cout << "Height: " << height << endl;
        }
        float calc1()
        {
            return (4 * PI * (radius*radius));
        }
        float calc2()
        {
            return ((4/3) * PI * (radius*radius*radius));
        }
};

int main()
{
    Circle circle1(5.8);
    circle1.display();
    cout << "Perimeter: " << circle1.calc1() << endl;
    cout << "Area: " << circle1.calc2() << endl;
    
    cout << "\n" <<endl;
    cout << "-----------------------------" << endl;
    cout << "\n" <<endl;

    Cylinder cylinder1(5.7, 4.5);
    cylinder1.display();
    cout << "Surface Area: " << cylinder1.calc1() << endl;
    cout << "Volume: " << cylinder1.calc2() << endl;

    return 0;
}