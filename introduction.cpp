#include <iostream>

using namespace std;
class Weather_report
{
private:
    int day_of_month;
    float hightemp, lowtemp, amount_rain, amount_snow;

public:
    Weather_report();
    void getdata();
    void displayData(int n);
    void Average(Weather_report w[], int n);
};
//set dafault values of data using constructor
Weather_report::Weather_report()
{
    hightemp = 0;
    lowtemp = 0;
    amount_rain = 0;
    amount_snow = 0;
    day_of_month = 0;
}
//for override the default value
void Weather_report::getdata()
{
    cout << "Enter the date of month :";
    cin >> day_of_month;
    cout << "\nEnter high Temp:";
    cin >> hightemp;
    cout << "\nEnter low Temp:";
    cin >> lowtemp;
    cout << "\nEnter Amt of Rain:";
    cin >> amount_rain;
    cout << "\nEnter Amt of Snow:";
    cin >> amount_snow;
}

// to display the data in tabular form
void Weather_report::displayData(int n)
{
    cout << "\n"
         << n;
    cout << "\t" << day_of_month
         << " \t" << hightemp
         << " \t\t" << lowtemp
         << " \t\t" << amount_rain
         << " \t\t" << amount_snow;
}

//to find the avarage of data
void Weather_report::Average(Weather_report data[], int n)
{
    //calculation for average of data
    for (int i = 0; i < n; ++i)
    {
        hightemp += data[i].hightemp;
        lowtemp += data[i].lowtemp;
        amount_rain += data[i].amount_rain;
        amount_snow += data[i].amount_snow;
    }
    hightemp = hightemp / n;
    lowtemp = lowtemp / n;
    amount_rain = amount_rain / n;
    amount_snow = amount_snow / n;

    //display the average data
    cout << "\n\tAverage High Temperature ="
         << hightemp;
    cout << "\n\tAverage Low Temperature ="
         << lowtemp;
    cout << "\n\tAverage Rainfall ="
         << amount_rain;
    cout << "\n\tAverage Snowfall ="
         << amount_snow;
}

int main()
{
    Weather_report data[32], average; //object of class
    int n = 0;
    int choice;

    do
    {
        cout << "\n  Main Menu";
        cout << "\n1. Enter Data.";
        cout << "\n2. Display Report.";
        cout << "\n3. Display Average Weather Report of month.";
        cout << "\n4. Exit.";
        cout << "\nEnter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // get data and store in array of object
            data[n++].getdata();

            break;
        case 2:
            // display all the data in proper format
            cout << "$\tDay\tHigh_Temp\tLow_Temp\tAmount_Rain\tAmount_Snow ";
            for (int i = 0; i < n; i++)
            {
                data[i].displayData(i + 1);
            }
            break;
        case 3:
            average.Average(data, n);

            break;
        }
    } while (choice != 4);
    return 0;
}
