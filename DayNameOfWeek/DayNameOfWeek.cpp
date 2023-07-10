#include <iostream>
#include <string>

using namespace std;

short DayOrderOfWeek(short Day, short Month, short Year)
{
    short a = (14 - Month) / 12 ;
    short y = Year - a;
    short m = Month + ( 12 * a) - 2 ;
    return ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    return arrDayNames[DayOfWeekOrder];
}

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

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    cout << "\nDate      : " << Day << "/" << Month << "/" << Year ;     
    cout << "\nDay Order : " << DayOrderOfWeek (Day, Month, Year);     
    cout << "\nDay Name  : " << DayShortName(DayOrderOfWeek(Day, Month, Year));
    system("pause>0");
}

