#include <iostream>
#include <string>

using namespace std;

struct stDate
{
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

short AddToDate()
{
    short Day;
    cout << "\nPlease Enter Number Day To Add ? ";
    cin >> Day;
    return Day;
}

bool IsYearLeap(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 4 == 0);
}

short NumberDayInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    int Day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2 ? (IsYearLeap(Year) ? 29 : 28) : Day[Month - 1]);
}

short TotalDaysInYear(short Day, short Month, short Year)
{
    short TotalDays = 0;
    for (short i = 0; i < Month; i++)
    {
        TotalDays += NumberDayInMonth(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

stDate
GetDateFromDayOrderInYear(short Day, stDate Date)
{
    short ReamingsDays = Day + TotalDaysInYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberDayInMonth(Date.Month, Date.Year);

        if (ReamingsDays > MonthDays)
        {
            ReamingsDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = ReamingsDays;
            break;
        }
    }
    return Date;
}

int main()
{
    stDate Date;
    Date = FullDate();
    short Day = AddToDate();

    Date = GetDateFromDayOrderInYear(Day, Date);

    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    system("pause>0");
}