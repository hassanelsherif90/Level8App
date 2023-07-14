#include <iostream>
#include <string>

using namespace std;

bool IsYearLeap(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
}

short NumberOfDays(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    int NumberDays[12] =
        {
            31, 28,
            31, 30,
            31, 30,
            31, 31,
            30, 31,
            30, 31};
    return (Month == 2 ? (IsYearLeap(Year) ? 29 : 28) : NumberDays[Month - 1]);
}

short TotalDaysInRange(short Day, short Month, short Year)
{
    int TotalDays;
    for (int i = 0; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDays(i, Year);
    }
    TotalDays += Day;
    return TotalDays;
}

short ReadDay()
{
    short Day;
    cout << "\nPlease Enter a day ? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "\nPlease Enter a month ? ";
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

void PrintTotalDays(short Day, short Month, short Year)
{
    cout << "Number of Days from the begining of the year is " << TotalDaysInRange(Day, Month, Year) << endl;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();
    PrintTotalDays(Day, Month, Year);
    system("pause>0");
}