#include <iostream>
#include <string>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year;
    cout << "\nPlease Enter a year ? ";
    cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease Enter a Month ? ";
    cin >> Month;
    return Month;
}

short ReadDay()
{
    short Day;
    cout << "\nPlease Enter a Day ? ";
    cin >> Day;
    return Day;
}

bool IsYearLeap(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberDaysInYear(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    int NumberDays[12] = {
        31, 28,
        31, 30,
        31, 30,
        31, 31,
        30, 31,
        30, 31};

    return (Month == 2 ? (IsYearLeap(Year) ? 29 : 28) : NumberDays[Month - 1]);
}

short TotalDaysBegingInYear(short Day, short Month, short Year)
{
    short TotalDays = 0;
    for (int i = 0; i < Month; i++)
    {
        TotalDays += NumberDaysInYear(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

stDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
{
    stDate Date;
    short ReamingDays = DaysOrderInYear;
    short MonthDay = 0;

    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDay = NumberDaysInYear(Date.Month, Year);

        if (ReamingDays > MonthDay)
        {
            ReamingDays -= MonthDay;
            Date.Month++;
        }
        else
        {
            Date.Day = ReamingDays;
            break;
        }
    }
    return Date;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    short DaysOrderInYear = TotalDaysBegingInYear(Day, Month, Year);

    cout << DaysOrderInYear << endl;
    stDate Date;
    Date = GetDateFromDayOrderInYear(DaysOrderInYear, Year);

    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    system("pause>0");
}