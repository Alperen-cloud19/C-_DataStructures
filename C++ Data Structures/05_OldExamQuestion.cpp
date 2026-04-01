#include <iostream>
#include <string>
using namespace std;

class Rect
{
    protected:
        float length;
        float width;
    public:
        Rect(float l = 1, float w = 1) : length(l), width(w) {}

        void setlength(float l)
        {
            length = l;
        }
        void setwidth(float w)
        {
            width = w;
        }
        float getlength()
        {
            return length;
        }
        float getwith()
        {
            return width;
        }
        void display()
        {
            cout << "Length: " << length << endl;
            cout << "Width: " << width << endl;
        }

        float calc1()
        {
            return (2 * (length + width));
        }
        float calc2()
        {
            return (length * width);
        }        
};

class RectangularPrism : public Rect
{
    private:
        float height;
    
    public:
        RectangularPrism(float len, float wid, float heig) : Rect(len, wid), height(heig) {}
    
        void setheight(float h)
        {
            height = h;
        }
        float getheight()
        {
            return height;
        }
        void display()
        {
            Rect::display();
            cout << "Height: " << height << endl;
        }
        float calc1()
        {
            return (2 * ((length * width) + (length * height) + (width * height)));
        }
        float calc2()
        {
            return (length * width * height);
        }
};

int main()
{
    // Base classdan bir nesne oluşturma işlemi
    Rect r1(4.5, 3.7);
    cout << "Rectangle: " << endl;
    r1.display();
    cout << "Rectangle radius: " << r1.calc1() << endl;
    cout << "Rectangle area: " << r1.calc2() << endl;

    // Derived classdan bir nesne oluşturma işlemi
    RectangularPrism rp1(3.0, 4.0, 5.0);
    cout << "\n Rectangular Prism: " << endl;
    rp1.display();
    cout << "Rectangular Prism surface area: " << rp1.calc1() << endl;
    cout << "Rectangular Prism volume: " << rp1.calc2() << endl;

    return 0;
}