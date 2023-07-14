#include <iostream>
#include <string>

using namespace std;

struct stDate{ 
    short Year;
    short Month;
    short Day;
};

short ReadDay()
{
    short Day;
    cout << "\nPlease Enter a Day ? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease Enter a Month ? ";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\nPlease Enter a Year ? ";
    cin >> Year;
    return Year;
}

stDate FullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
    return ((Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Year) ? true :(Date1.Month == Date2.Year) ? (Date1.Day < Date2.Day) : false : false);
}

int main()
{
    stDate Date1 = FullDate();
    stDate Date2 = FullDate();

    if(IsDate1LessThanDate2(Date1, Date2)) 
    {
        cout << "\nDate 1 Less Than Date 2 \n";
    }
    else
    {
        cout << "\nDate 2 Less Than Date 1 \n";
    }
}