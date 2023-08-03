#include <iostream>

using namespace std;

enum enCompareDate
{
    enBefore = -1,
    enEqual = 0,
    enAfter = 1
};

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1EqualeDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1AfterDate2(Date1, Date2));
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
    while (IsDate1BeforeDate2(Date1, Date2))
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

enCompareDate CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::enBefore;

    if (IsDate1EqualeDate2(Date1, Date2))
        return enCompareDate::enEqual;

    return enCompareDate::enAfter;
}

bool IsOverLapPerides(stPeriod Period1, stPeriod Period2)
{
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) == enCompareDate::enBefore ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enCompareDate::enAfter)
        return false;
    else
        return true;
}

bool isDateInPeriod(stDate Date, stPeriod Period)
{
    return !(
        CompareDates(Date, Period.StartDate) == enCompareDate::enBefore ||
        CompareDates(Date, Period.EndDate) == enCompareDate::enAfter);
}

int CounterIsOverLapDays(stPeriod Period1, stPeriod Period2)
{
    int Period1Length = PeriodLengthDays(Period1, true);
    int Period2Length = PeriodLengthDays(Period2, true);
    int OverLapDays = 0;

    if (!IsOverLapPerides(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if (isDateInPeriod(Period1.StartDate, Period1))
                OverLapDays++;
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }
    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (isDateInPeriod(Period2.StartDate, Period2))
                OverLapDays++;
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }

    return OverLapDays;
}

int main()
{
    cout << "\nEnter Period 1 : ";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 2 : ";
    stPeriod Period2 = ReadPeriod();

    cout << "\nPeriod Lenght Is : " << CounterIsOverLapDays(Period1, Period2) << endl;

    system("pause>0");
}
