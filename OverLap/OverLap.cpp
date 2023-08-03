#include <iostream>

using namespace std;

struct stDate
{
    short Day;
    short Month;
    short Year;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
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

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Period  : \n";
    Period.StartDate = FullDate();

    cout << "\nEnter End Period  :  \n";
    Period.EndDate = FullDate();
    return Period;
}

bool IsOverLapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (
        CompareDate(Period2.EndDate, Period1.StartDate) == enCompareDate::enBefore ||
        CompareDate(Period2.StartDate, Period1.EndDate) == enCompareDate::enAfter)
        return false;
    else
        return true;
}

bool IsInOverLap(stDate Date, stPeriod Period)
{
    return !(
        CompareDate(Date, Period.StartDate) == enCompareDate::enBefore ||
        CompareDate(Date, Period.EndDate) == enCompareDate::enAfter);
}

int CounterOverLap(stPeriod Period1, stPeriod Period2)
{
    int Counter = 0;
    while (IsOverLapPeriods(Period1, Period2))
    {
        Counter++;
    }
    return Counter;
}

int main()
{
    cout << "\nEnter Period 1 : \n";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2 : \n";
    stPeriod Period2 = ReadPeriod();

    // if (IsOverLapPeriods(Period1, Period2))
    //     cout << "\nYes : Periods OverLap \n";
    // else
    //     cout << "\nNo : Periods do not OverLap \n";

    cout << "\nOverLap Counter Is : " << CounterOverLap(Period1, Period2) << endl;

    system("pause>0");
}