#include <iostream>

using namespace std;

class number
{
protected:
    //data member for taking two numbers
    double a, b;

public:
    //accepting two number
    void accept();

    //calculate division of two number
    void division();
};

//accepting two number
void number::accept()
{
    cout << "Enter two number \n";
    cin >> a >> b;
}

//calculate division of two number
void number::division()
{
    if (b != 0)
    {
        double result = a / b; //division
        cout << "Division of given Number(" << a << "/" << b << ") is " << result;
    }
    else
    { //if divident is zero than throw error
        throw(b);
    }
}

int main()
{

    int choice;
    number n1;

    while (choice != 3)
    { //main menu
        cout << "\nMENU:\n 1. Accept Two Number\n 2.Division \n 3.Exit";
        cout << "\nEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            //accept two number
            n1.accept();
            break;
        case 2:
            //calculating division
            try
            {
                n1.division();
            }
            catch (double b)
            {
                //catch error of divident is zero
                cout << "Denominator can not be zero. Give proper Inputs \n";
            }
            break;
        case 3:
            //exit the execution
            break;

        default:
            //for dealing of wrong choice
            cout
                << "Invalid Choice.\n";
            break;
        }
    }
    return 0;
}