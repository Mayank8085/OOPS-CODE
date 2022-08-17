#include <iostream>

using namespace std;

//Base Class
class size
{
protected:
    //data member for taking sides
    double length, breath;

public:
    //member function to get sides
    void getdata(double, double);

    //  pure virtual function and use default argument
    virtual double compute_area() = 0;
};

// define get function
// and using default argument
void size::getdata(double l, double b = 1)
{
    length = l;
    breath = b;
};

// derived class for triangle
class triangle : public size
{

public:
    double compute_area();
};

// derived class for rectangle
class rectangle : public size
{
public:
    double compute_area();
};

// derived class for cricle
class circle : public size
{

public:
    double compute_area();
};

//define function for area of triangle
double triangle ::compute_area()
{
    return (0.5 * length * breath);
};

//define function for area of rectangle
double rectangle ::compute_area()
{
    return (length * breath);
};

//define function for area of circle
double circle::compute_area()
{
    return 3.14 * (length * length);
}

//main function
int main()
{
    //define variable for choice
    int choice;
    double result;
    double l, b;

    //pointer of size
    size *s1;

    // objects of classes
    triangle t;
    rectangle r;
    circle c;

    do
    {
        cout << "\n *** MENU ***";
        cout << "\n 1. For Area Of Triangle \n 2. For Area Of Rectangle \n 3. For Area of Circle \n 4. For Exit  ";
        cout << "\nEnter Your Choice\n";
        cin >> choice;
        switch (choice)
        {
            //for area of triangle
        case 1:
            cout << "Enter Sides of Triangle\n";
            cin >> l >> b;
            s1 = &t;
            s1->getdata(l, b);
            result = s1->compute_area();
            cout << "\n\tArea of Triangle = " << result << " unit^2";
            break;

        //for area of rectangle
        case 2:
            cout << "Enter Sides of Rectangle\n";
            cin >> l >> b;
            s1 = &r;
            s1->getdata(l, b);
            result = s1->compute_area();
            cout << "\n\tArea of Rectangle = " << result << " unit^2";
            break;

        //for area of circle
        case 3:
            cout << "Enter Radius of Circle\n";
            cin >> l;
            s1 = &c;
            s1->getdata(l);
            result = s1->compute_area();
            cout << "\n\tArea of circle = " << result << " unit^2";
            break;

        default:
            break;
        }
    } while (choice != 4);

    return 0;
}
