#include <iostream>

using namespace std;

template <class T1, class T2>

// define matrix class
class matrix
{

    T1 mat1[20][20];
    T2 mat2[20][20];
    T2 mat3[20][20];

    int r1, c1, r2, c2;

public:
    void getMatrix();      // for getting matrix
    void display();        //for display the matrix
    void addition();       //perform addition
    void subtraction();    //perform subtraction
    void multiplication(); //perform multiplication
};

// getting two matrix from user
template <class T1, class T2>
void matrix<T1, T2>::getMatrix()
{
    cout << "Enter the Number of Row and Column of Matrix 1\n";
    cin >> r1 >> c1;
    cout << "Enter the element \n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << "\nEnter the element of [" << i << "][" << j << "]position: ";
            cin >> mat1[i][j];
        }
    }
    cout << "Enter the Number of Row and Column of Matrix 2\n";
    cin >> r2 >> c2;
    cout << "Enter the element \n";
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << "\nEnter the element of [" << i << "][" << j << "]position: ";

            cin >> mat2[i][j];
        }
    }
}

//display two matrix
template <class T1, class T2>
void matrix<T1, T2>::display()
{
    cout << "matrix 1 are: \n";
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << "\t" << mat1[i][j];
        }
        cout << "\n";
    }
    cout << "\nmatrix 2 are: \n";
    for (int i = 0; i < r2; i++)
    {

        for (int j = 0; j < c2; j++)
        {
            cout << "\t" << mat2[i][j];
        }
        cout << "\n";
    }
}

//perform addition of two matrix
template <class T1, class T2>
void matrix<T1, T2>::addition()
{
    if (r1 == r2 && c1 == c2)
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        cout << "\nAddition of given Matrix are \n";
        for (int i = 0; i < r2; i++)
        {

            for (int j = 0; j < c2; j++)
            {
                cout << "\t" << mat3[i][j];
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "Addition not possible \n";
    }
}

//perform subtraction of two matrix
template <class T1, class T2>
void matrix<T1, T2>::subtraction()
{
    if (r1 == r2 && c1 == c2)
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                mat3[i][j] = mat1[i][j] - mat2[i][j];
            }
        }
        cout << "\nSubtraction of given Matrix are \n";

        for (int i = 0; i < r2; i++)
        {

            for (int j = 0; j < c2; j++)
            {
                cout << "\t" << mat3[i][j];
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "Subtraction is not possible\n";
    }
}

//perform multiplication of two  matrix
template <class T1, class T2>
void matrix<T1, T2>::multiplication()
{
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            mat3[i][j] = 0;
        }
    }

    if (c1 == r2)
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {

                for (int k = 0; k < c1; k++)
                {
                    mat3[i][j] = mat1[i][k] * mat2[k][j];
                }
            }
        }
        cout << "\nMultiplication of given Matrix are \n";

        for (int i = 0; i < r2; i++)
        {

            for (int j = 0; j < c2; j++)
            {
                cout << "\t" << mat3[i][j];
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "multiplication is not possible \n1";
    }
}

//main function
int main()
{
    int choice, cho, p;
    do
    {
        //Menu for type of data
        cout << "Choice data type \n\t 1) <int,int> \n\t 2) <float,float> \n\t 3) <int,float> \n\t 4) Exit \n";
        cout << "Choice Choice \n";
        cin >> choice;
        switch (choice)
        {
        //if data type is int,int
        case 1:

            matrix<int, int> a;
            a.getMatrix();
            a.display();
            do
            {
                //menu for performing matrix operation
                cout << "\n MENU\n 1. Addition 2. Subtraction 3. Multiplication \n";
                cout << "Enter choice \n";
                cin >> cho;
                switch (cho)
                {
                case 1:
                    a.addition();

                    break;
                case 2:
                    a.subtraction();

                    break;

                case 3:
                    a.multiplication();

                    break;
                default:
                    cout << "Wrong Choice";
                    break;
                }
                cout << "for continue press 1 and for exist press 0 \n";
                cin >> p;

            } while (p == 1);

            break;

            //if data type is float,float
        case 2:

            matrix<float, float> b;
            b.getMatrix();
            b.display();
            do
            {
                //menu for performing matrix operation

                cout << "\n MENU\n 1. Addition 2. Subtraction 3. Multiplication \n";
                cout << "Enter choice \n";
                cin >> cho;
                switch (cho)
                {
                case 1:
                    b.addition();

                    break;
                case 2:
                    b.subtraction();

                    break;

                case 3:
                    b.multiplication();

                    break;
                default:
                    cout << "Wrong Choice";
                    break;
                }
                cout << "for continue press 1 and for exist press 0 \n";
                cin >> p;

            } while (p == 1);

            break;

        //if data type is int,float
        case 3:
            matrix<int, float> c;
            c.getMatrix();
            c.display();
            do
            {
                //menu for performing matrix operation
                cout << "\n MENU\n 1. Addition 2. Subtraction 3. Multiplication \n";
                cout << "Enter choice \n";
                cin >> cho;
                switch (cho)
                {
                case 1:
                    c.addition();

                    break;
                case 2:
                    c.subtraction();

                    break;

                case 3:
                    c.multiplication();

                    break;
                default:
                    cout << "Wrong Choice";
                    break;
                }
                cout << "for continue press 1 and for exist press 0\n";
                cin >> p;

            } while (p == 1);

            break;
        case 4:
            break;

        default:
            cout << "Wrong Input";
            break;
        }
    } while (choice != 4);

    return 0;
}
