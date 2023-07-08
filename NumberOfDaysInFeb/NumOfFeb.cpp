#include <iostream>
#include <string>

using namespace std;

bool IsLeapYear ( short Year )
{
return ( ( Year % 4 == 0 && Year % 100 != 0 ) || ( Year % 400 == 0 ) );
}

short NumberOfDay ( short Month , short Year )
{
    if ( Month < 1 || Month > 12 )
    {
        return 0;
    }
    if ( Month == 2 )
    {
        return ( IsLeapYear ( Year ) ? 29 : 28 );
    }
    short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };
    for ( short i = 1; i < 7; i++ )
    {
    if ( arr31Days[i - 1] == Month )
    {
        return 31;
    }
}
return 30;
}

short NumberOfDays ( short Month , short Year )
{
    if ( Month < 1 || Month > 12 )
        return 0;
    int NumberDaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return ((Month == 2 ) ? (IsLeapYear(Year) ? 29 : 28 ) : NumberDaysInMonth[Month - 1]);
}

int NumberOfHours ( short Month , short Year )
{
return ( NumberOfDays ( Month , Year ) * 24 );
}

int NumberOfMinutes ( short Month , short Year )
{
    return ( NumberOfHours ( Month , Year ) * 60 );
}

int NumberOfSeconds ( short Month , short Year )
{
    return ( NumberOfMinutes ( Month , Year ) * 60 );
}

short ReadYear ( )
{
    short Year;
    cout << "\nEnter Your Year ? ";
    cin >> Year;
    return Year;
}

short ReadMonth ( )
{
    short Month;
    cout << "\nEnter Your Month ? ";
    cin >> Month;
    return Month;
}

void PrintAll ( short Month , short Year )
{
    cout << "Number Of Days in Year     [ " << Year << "] : " << NumberOfDays ( Month , Year ) << endl;
    cout << "Number Of Hours in Year    [ " << Year << "] : " << NumberOfHours ( Month , Year ) << endl;
    cout << "Number Of Minutes in Year  [ " << Year << "] : " << NumberOfMinutes ( Month , Year ) << endl;
    cout << "Number Of Seconds in Year  [ " << Year << "] : " << NumberOfSeconds ( Month , Year ) << endl << endl;
}

int main ( )
{
    short Year = ReadYear ( );
    short Month = ReadMonth ( );
    PrintAll ( Month , Year );
    system ( "pause>0" );
}