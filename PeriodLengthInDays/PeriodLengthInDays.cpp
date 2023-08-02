#include <iostream>

using namespace std;

struct stDate
{
    short Day;
    short Month;
    short Year;
};

bool IsYearLeap(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
}

short NumberDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2 ? IsYearLeap(Year) ? 29 : 28 : Days[Month - 1]);
}

bool LastMonth(short Month)
{
    return (Month == 12);
}

bool LastDayInMonth(stDate Date)
{
    return (Date.Day == NumberDaysInMonth(Date.Month, Date.Year));
}

stDate IncreaseDateByOneDay(stDate Date)
{
    if (LastDayInMonth(Date))
    {
        if (LastMonth(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

bool IsDate1BforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterleDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1AfterleDate2(Date1, Date2) && !IsDate1EqualeDate2(Date1, Date2));
}

short ReadDay()
{
    cout << "please enter day ? ";
    short Day;
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    cout << "please enter month ? ";
    short month;
    cin >> month;
    return month;
}

short ReadYear()
{
    cout << "please enter year ? ";
    short year;
    cin >> year;
    return year;
}

stDate FullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Period : \n";
    Period.StartDate = FullDate();

    cout << "\nEnter End Period : \n";
    Period.EndDate = FullDate();
    return Period;
}

int GetDifferanceDays(stDate Date1, stDate Date2, bool IncludeDay = false)
{
    int Days = 0;
    while (IsDate1BforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeDay ? ++Days : Days;
}

int PeriodLengthDays(stPeriod Period, bool IncludeEndDate = false)
{
    return GetDifferanceDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}

int main()
{
    stPeriod Period = ReadPeriod();

    cout << "\nPeriod Lenght Is : " << PeriodLengthDays(Period) << endl;
    cout << "\nPeriod Lenght Include Day Is : " << PeriodLengthDays(Period, true) << endl;

    system("pause>0");
}
