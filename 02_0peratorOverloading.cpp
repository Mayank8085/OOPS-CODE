#include <iostream> 
using namespace std;

class complex
{
private:
    float real;
    float imaginary;

public:
    // default constructors
    complex()
    {
        real = 0;
        imaginary = 0;
    }
    // parameterized constructors
    complex(float r, float i)
    {
        real = r;
        imaginary = i;
    }

    void getData();
    void displayData();

    //friend function & operator overloading
    friend complex operator+(complex n1, complex n2);
    friend complex operator-(complex n1, complex n2);

    //operator overloading
    complex operator*(complex n1);
    complex operator/(complex n1);
};

// to get the real and imaginary part of number
void complex::getData()
{
    cout << "Enter the Real part of Number" << endl;
    cin >> real;
    cout << "Enter the Imaginary part of Number" << endl;
    cin >> imaginary;
};

//display the complex number
void complex ::displayData()
{
    cout << real << "+" << imaginary << "i" << endl;
}

//addition of two complex number
complex operator+(complex n1, complex n2)
{
    complex n;
    n.real = n1.real + n2.real;
    n.imaginary = n1.imaginary + n2.imaginary;
    return n;
}

//subtraction of two complex number
complex operator-(complex n1, complex n2)
{
    complex n;
    n.real = n1.real - n2.real;
    n.imaginary = n1.imaginary - n2.imaginary;
    return n;
}

//multiplication of two complex number
complex complex::operator*(complex n1)
{
    complex n;
    n.real = (real * n1.real - imaginary * n1.imaginary);
    n.imaginary = (n1.real * imaginary + real * n1.imaginary);
    return n;
}

//division of two complex number
complex complex::operator/(complex n1)
{
    complex n;

    n.real = (real * n1.real + imaginary * n1.imaginary) / ((n1.real) * (n1.real) + (n1.imaginary) * (n1.imaginary));      //(a1a2+b1b2)/(a2a2+b2b2)
    n.imaginary = (imaginary * n1.real - real * n1.imaginary) / ((n1.real) * (n1.real) + (n1.imaginary) * (n1.imaginary)); //(b1a2-a1b2)/(a2a2+b2b2)
    return n;
}

int main()
{
    int choice = 0;
    complex c1, c2, c3; //object of class

    // get the two complex number
    cout << "Enter the first Complex Number" << endl;
    c1.getData();
    cout << "Enter the second Complex Number" << endl;
    c2.getData();
    cout << "First Complex Number is =>" << endl;
    c1.displayData();
    cout << "Second Complex Number is =>" << endl;
    c2.displayData();

    while (choice != 5)
    {
        //main menu
        cout << "\nEnter:\n1 For Addition\n2 For Substraction\n3 For Multiplication\n4 For division\n5 For exit\n";
        cin >> choice;
        switch (choice)
        {
        //addition
        case 1:
            c3 = c1 + c2;
            cout << "\n Addition of Given Numbers is: ";
            c3.displayData();
            break;

        //subtraction
        case 2:
            c3 = c1 - c2;
            cout << "\n Subtraction of Given Numbers is: ";
            c3.displayData();
            break;

        //multiplication
        case 3:
            c3 = c1 * c2;
            cout << "\n Multiplication of Given Numbers is: ";
            c3.displayData();
            break;

        //division
        case 4:
            c3 = c1 / c2;
            cout << "\n Division of Given Numbers is: ";
            c3.displayData();
            break;

        //exit
        case 5:
            break;

        //invalid choice
        default:
            cout << "\n Invalid Choice\n Enter Choice Properly";
        }
    }

    return 0;
}
