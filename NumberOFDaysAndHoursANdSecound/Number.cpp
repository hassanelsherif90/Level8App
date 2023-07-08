#include <iostream>
#include <string>

using namespace std;

bool IsYearLeap( short Year )
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDays(short Year)
{
    return ( IsYearLeap( Year ) ? 366 : 365);
}

int NumberOfHours(short Year)
{
    return (NumberOfDays(Year) * 24 );
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
        cout << "Number Of Days in Year     [ " << Year << "] : " << NumberOfDays(Year) << endl;
        cout << "Number Of Hours in Year    [ " << Year << "] : " << NumberOfHours(Year) << endl;
        cout << "Number Of Minutes in Year  [ " << Year << "] : " << NumberOfMinutes(Year)<< endl;
        cout << "Number Of Seconds in Year  [ " << Year << "] : " <<NumberOfSeconds(Year) << endl << endl;
}

int main()
{
    short Year = ReadYears();
    PrintAll(Year);

    // system("pause>0");
}