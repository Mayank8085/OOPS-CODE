#include <iostream>
#include <fstream>
using namespace std;

//class for information
class Student
{
protected:
    char name[50];
    int rollNo;
    int marks;

public:
    void getData();                     //get data
    void displayData();                 //display data
    int getRollNo() { return rollNo; }; //give roll no
};

//get data from user
void Student::getData()
{
    cout << "Enter Name of Student: ";
    cin >> name;
    cout << "Enter Roll No of Student: ";
    cin >> rollNo;
    cout << "Enter Total Marks of Student: ";
    cin >> marks;
}

//display data
void Student::displayData()
{
    cout << "Name of Student: " << name << endl;
    cout << " Roll No of Student: " << rollNo << endl;
    cout << "Total Marks of Student: " << marks << endl;
}

//class for storing data in file
class Students
{
    Student s;

public:
    void Add();     //add data in file
    void Display(); //display data from file
    void Search();  //search data  from file
    void Modify();  //modify data in the file
    void Delete();  //delete data from file
};

// adding data in file
void Students::Add()
{
    char ch = 'y';
    ofstream fop("student.dat", ios::out | ios::app | ios::binary);
    while (ch == 'y' | ch == 'Y')
    {
        s.getData();
        fop.write((char *)&s, sizeof(s)); //write data in file
        cout << "\nDo you wish to add more: ";
        cin >> ch;
    }
    cout << "\nData added to file\n";
    fop.close();
}

//display all data of the file
void Students::Display()
{
    ifstream fip("student.dat", ios::in | ios::binary); //open file in read mode
    while (fip.read((char *)&s, sizeof(s)))
    {
        s.displayData();
    }
    fip.close();
}

//search data from the file
void Students::Search()
{
    ifstream fip("student.dat", ios::in | ios::binary);
    int rollno, i = 0;
    char found = 'n';
    cout << "\nEnter the roll number to be searched: ";
    cin >> rollno;
    while (fip.read((char *)&s, sizeof(s)))
    {
        if (s.getRollNo() == rollno) //check given roll no is there in file or not
        {
            s.displayData();
            found = 'y';
        }
        i++;
    }
    if (found == 'n')
        cout << "\nThe Roll no " << rollno << "is not in the file.\n";
    fip.close();
}

// Modify data in file
void Students::Modify()
{
    fstream fio("student.dat", ios::in | ios::out | ios::binary);
    int rollno;
    char found = 'n';
    fio.seekg(0); //point to start of the file
    cout << "\nEnter the Roll No. whose record is to be modified: ";
    cin >> rollno;
    while (fio)
    {
        int loc = fio.tellg(); //taking location of data
        fio.read((char *)&s, sizeof(s));
        if (s.getRollNo() == rollno)
        {
            s.getData();
            found = 'y';
            fio.seekg(loc);
            fio.write((char *)&s, sizeof(s));
            cout << "\nYour record of Roll No. " << rollno << " has been updated" << endl;
        }
    }
    if (found == 'n')
        cout << "\nThe Roll no " << rollno << "is not in the file.\n";
    fio.close();
}

// delete data from file
void Students::Delete()
{
    int rollno;
    char found = 'n';
    fstream fio("student.dat", ios::in | ios::out | ios::app | ios::binary);
    ofstream fout("temp.dat", ios::out | ios::binary | ios::app); //create temporary file
    ofstream out("trash.dat", ios::out | ios::binary | ios::app); //create trash file to store delete data
    cout << "Enter the Roll No whose record is to be deleted: ";
    cin >> rollno;
    while (fio.read((char *)&s, sizeof(s)))
    {
        if (s.getRollNo() == rollno)
        {
            out.write((char *)&s, sizeof(s));
            found = 'y';
        }
        else
        {
            fout.write((char *)&s, sizeof(s));
        }
    }
    if (found == 'n')
        cout << "\nThe Roll no " << rollno << "is not in the file.\n";
    fio.close();
    fout.close();
    remove("student.dat");             //remove old file
    rename("temp.dat", "student.dat"); //rename temporary file to student.dat
}

int main()
{
    int choice;

    Students S;
    do
    {
        cout << "MENU \n 1.Add Data \n 2.Display Data \n 3.Search Data \n 4.Modify Data \n 5.Delete Data\n 6.Exit";
        cout << "\nEnter choice";
        cin >> choice;
        switch (choice)
        {
            //add record in file
        case 1:
            cout << "Adding Record \n";
            S.Add();
            break;

            // display data of file
        case 2:
            cout << "Display Data \n";
            S.Display();
            break;

            //search data from file
        case 3:
            cout << "Search Record\n";
            S.Search();
            break;

            // modify data from file
        case 4:
            cout << "Modify Record\n";
            S.Modify();
            break;

            //delete data in file
        case 5:
            cout << "Delete Record\n";
            S.Delete();
            break;

            //exit the program
        case 6:
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
