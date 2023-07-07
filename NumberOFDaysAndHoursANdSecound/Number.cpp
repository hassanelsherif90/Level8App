#include <iostream>
#include <string>

using namespace std;

bool IsYearLeap( short Year )
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberDays(short Year)
{
    return ( IsYearLeap( Year ) ? 366 : 365);
}

int NumberOfHours(short Year)
{
    return (NumberDays(Year) * 24 );
}

int NumberOfMinutes(short Year)
{
    return (NumberOfHours( Year) * 60 );
}

int NumberOfSeconds(short Year)
{
    return (NumberOfMinutes(Year) * 60 );
}

short ReadYears()
{
    short Year;
    cout << "\nEnter Your Year ? ";
    cin >> Year;
    return Year;
}

void PrintAll(short Year)
{
    cout << "\nNumber Of Days in Year [ " <<  Year << "] : " << NumberDays(Year) << endl;
    cout << "\nNumber Of Hours in Year [ " <<  Year << "] : " << NumberOfHours(Year) << endl;
    cout << "\nNumber Of Minutes in Year [ " <<  Year << "] : " << NumberOfMinutes(Year)<< endl;
    cout << "\nNumber Of Seconds in Year [ " <<  Year << "] : " <<NumberOfSeconds(Year) << endl;
}

int main()
{
    short Year = ReadYears();
    PrintAll(Year);

    system("pause>0");
}