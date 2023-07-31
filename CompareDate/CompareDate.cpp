#include <iostream>

using namespace std;

struct stDate
{
    short Day;
    short Month;
    short Year;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
}

enum enCompareDate
{
    enBefore = -1,
    enEqual = 0,
    enAfter = 1
};

enCompareDate CompareDate(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
    {
        return enCompareDate::enBefore;
    }

    if (IsDate1EqualDate2(Date1, Date2))
    {
        return enCompareDate::enEqual;
    }

    return enCompareDate::enAfter;
}

short ReadDay()
{
    cout << "please enter a Day ? ";
    short Day;
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    cout << "please enter a month ? ";
    short Month;
    cin >> Month;
    return Month;
}

short ReadYear()
{
    cout << "please enter a year ? ";
    short Year;
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

int main()
{
    cout << "\nEnter Date1 : \n";
    stDate Date1 = FullDate();

    cout << "\nEnter Date2 : \n";
    stDate Date2 = FullDate();

    cout << "\nCompare Date Is : " << CompareDate(Date1, Date2) << endl;

    system("pause>0");

    return 0;
}