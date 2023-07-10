#include <iostream>
#include <string>

using namespace std;

short ReadYear()
{
    short Year;
    cout << "\nPlease Enter a Year ? ";
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

bool IsLeapYear(short Year)
{
    return (((Year % 4 == 0 ) && (Year % 100 != 0)) ||( Year % 400 == 0));
}

short DayOrderOfWeek(short Day, short Month, short Year)
{
    short a = (14 - Month) / 12 ;
    short y = Year - a;
    short m = Month + ( 12 * a) - 2 ;
    return ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
}

short NumberOfDaysInYear ( short Month , short Year )
{
    if ( Month < 1 || Month > 12 )
        return 0;

    int NumberDaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    return ((Month == 2 ) ? (IsLeapYear(Year) ? 29 : 28 ) : NumberDaysInMonth[Month - 1]);
}

string NameOfMonth(short Month)
{
    string arrMonth [12] = 
                            { 
                                "Jan", "Feb", "Mar",
                                "Apr", "May", "Jun",
                                "Jul", "Aug", "Des",
                                "Oct", "Nov", "Dec"
                            };

    return arrMonth[Month - 1];
}

void PrintCalender(short Year, short Month)
{
    int NumberOfDays ;
    short Curent = DayOrderOfWeek(1, Month, Year);
    NumberOfDays = NumberOfDaysInYear(Month, Year);

    printf("\n----------------------%s------------------------------\n", NameOfMonth(Month).c_str());
    printf("\n   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
    int i ;
    for (i = 0 ; i < Curent ; i++)
        printf("     ");
    
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if ( ++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n----------------------------------------------------\n");
}


int main()
{
    short Year  = ReadYear();
    short Month = ReadMonth();
    PrintCalender(Year, Month);
    // system("pause>0"); // For Windows
}
