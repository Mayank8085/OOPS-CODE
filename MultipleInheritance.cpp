#include <iostream>
#include <string.h>
using namespace std;
class base1
{
protected:
    //declaring data member
    char name[20], bloodgroup[10];
    char DateofBirth[20];

public:
    // Takes input name, bloodgroup from the user
    void getData1();
    // Displays name and bloodgroup
    void putData1();
};
class base2
{
    //declaring data member
protected:
    float height, weight;

public:
    // Takes input height, weight from the user
    void getData2();
    // Displays height and weight
    void putData2();
};
class base3
{
    //declaring data member
protected:
    int insuranceNo;
    char address[20];

public:
    // Takes input insurance no, address from the user
    void getData3();
    // Displays insuranceNo and address
    void putData3();
};
// use inheritance concept to access data member of base classes
class derive : public base1, public base2, public base3
{
protected:
    int telNo;
    int drivingLic;

public:
    void accept();           //for accept data
    void display();          // for display data
    int search(char na[20]); //for search data
    void modify();           //for modify data
};

// Takes input name, bloodgroup from the user
void base1::getData1()
{
    cout << "\n\tEnter the name: ";
    cin >> name;
    cout << "\n\tEnter the Date of Birth(dd/mm/yy): ";
    cin >> DateofBirth;
    cout << "\n\tEnter the blood group: ";
    cin >> bloodgroup;
}

// Displays name and bloodgroup
void base1::putData1()
{
    cout << name << "\t";
    cout << DateofBirth << "\t";
    cout << bloodgroup << "\t";
}

// Takes input height, weight from the user
void base2::getData2()
{
    cout << "\n\tEnter the height: ";
    cin >> height;
    cout << "\n\tEnter the weight: ";
    cin >> weight;
}

// Displays height and weight
void base2::putData2()
{
    cout << height << "\t";
    cout << weight << "\t";
}

// Takes input insurance no, address from the user
void base3::getData3()
{
    cout << "\n\tEnter the insurance policy number: ";
    cin >> insuranceNo;
    cout << "\n\tEnter the contact address: ";
    cin >> address;
}

// Displays insuranceNo and address
void base3::putData3()
{
    cout << insuranceNo << "\t";
    cout << address << "\t";
}

//accept all data
void derive::accept()
{
    getData1();
    getData2();
    getData3();
    cout << "\n\tEnter the telephone number: ";
    cin >> telNo;
    cout << "\n\tEnter the license number: ";
    cin >> drivingLic;
}

//display all data
void derive::display()
{
    putData1();
    putData2();
    putData3();
    cout << telNo << "\t";
    cout << drivingLic << "\n";
}

//search data by camparing name
int derive::search(char na[20])
{
    if (strcmp(na, name) == 0)
        return 1;
    else
        return 0;
}

//modify data
void derive::modify()
{
    int choice = 0;
    cout << "Menu \n 1. Do you want to modify all data \n2. Modify name \n3. Modify Date of Birth \n4. Modify blood grp \n5. Modify Height \n6. Modify Weight \n7. Modify Address \n8. Modify insurance no \n9. Modify Telephone No. \n 10. Modify Driving License No.  ";
    cout << "Enter the choice";
    cin >> choice;
    switch (choice)
    {
    case 1:
        //modify all data
        accept();
        break;
    case 2:
        //modify name only
        cout << "Enter New Name\n";
        cin >> name;
        break;
    case 3:
        //modify Date of Birth only
        cout << "Enter New date of birth\n";
        cin >> DateofBirth;
        break;
    case 4:
        //modify blood group only
        cout << "Enter New blood group\n";
        cin >> bloodgroup;
        break;
    case 5:
        //modify height only
        cout << "Enter New Height\n";
        cin >> height;
        break;
    case 6:
        //modify weight only
        cout << "Enter New Weight\n";
        cin >> weight;
        break;
    case 7:
        //modify Address only
        cout << "Enter New Address\n";
        cin >> address;

        break;
    case 8:
        //modify Insurance only
        cout << "Enter New Insurance no\n";
        cin >> insuranceNo;
        break;
    case 9:
        //modify Telephone only
        cout << "Enter New Telephone no\n";
        cin >> telNo;
        break;
    case 10:
        //modify Driving Licence only
        cout << "Enter New Driving Licence no\n";
        cin >> drivingLic;
        break;

    default:
        break;
    }
}

int main()
{
    derive d1[20]; //object
    int choice = 0, i, n = 0;
    char nam[20];
    while (choice != 7)
    { //main menu
        cout << "MENU:\n 1.Build a Master Table\n2.Display \n3.Insert New Entry \n4.Delete Entry\n5.Edit\n6.Search for a Record\n 7. Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        //executes accourding to choice
        switch (choice)
        {
        case 1:
            //accept data
            cout << "Enter no.of data to be accepted\n";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                d1[i].accept();
            }

            break;
        case 2:
            //display data
            cout << "#\tName\tBloodGroup\tDateofBirth\tHeight\tWeight\tAddress\tInsuranceNo\tTelephoneNo \tDivingLicence\n";

            for (i = 0; i < n; i++)
            {
                cout << i + 1 << "\t";
                d1[i].display();
            }
            break;

        case 3:
            //insert data
            n++;
            d1[n - 1].accept();
            cout << "Data Insert Successfully \n";
            break;

        case 4:
            //delete data
            cout << "Enter the name which you want to delete\n";
            cin >> nam;
            for (i = 0; i < n; i++)
            {
                if (d1[i].search(nam))
                {
                    cout << "Data deleted successfully \n";
                    while (i < n - 1)
                    {
                        d1[i] = d1[i + 1];
                        i++;
                    }
                    n--;
                    break;
                }
            }
            //if data not found
            if (i == n)
            {
                cout << "Data Not Found \n";
            }
            break;

        case 5:
            //edit data
            cout << "Enter the name of data which you want to edit\n";
            cin >> nam;
            for (i = 0; i < n; i++)
            {
                if (d1[i].search(nam))
                {
                    d1[i].modify();
                    break;
                }
            }
            //if data not found
            if (i == n)
            {
                cout << "Data Not Found \n";
            }
            break;

        case 6:
            //search Data
            cout << "Enter the name of data which you want to search \n";
            cin >> nam;
            for (i = 0; i < n; i++)
            {
                if (d1[i].search(nam))
                {
                    cout << "# \t Name \t BloodGroup \t DateofBirth \t Height \t Weight \t Address \tInsuranceNo \tTelephoneNo \t DivingLicence \n";
                    d1[i].display();
                }
            }
            //data not found
            if (i == n)
            {
                cout << "Data Not Found \n";
            }
            break;
        }
    }
}