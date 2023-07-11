#include <iostream>
#include <string>

using namespace std;

bool IsYearLeap(short Year)
{
    return(((Year % 4 == 0) && (Year % 100 != 0)) ||( Year % 400 == 0)); 
}

short  DayOfWeekOrder(short Day, short Month , short Year)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;
    //((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7)
    return ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
}

short NumberofDaysInYear(short Month, short Year)
{
    if ( Month < 1 || Month > 12 )
        return 0;

    int NumberDaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return ((Month == 2 ) ? (IsYearLeap(Year) ? 29 : 28) : NumberDaysInMonth[Month - 1]);
}

string NameMonth(short Month)
{
    string NameOfMonth[12] =
                            {
                                "Jan", "Feb", "Mar",
                                "Apr", "May", "Jun",
                                "Jul", "Aug", "Des",
                                "Oct", "Nov", "Dec"
                            };
        return NameOfMonth[Month - 1];
}

void PrintMonthCalander(short Month, short Year)
{
    int NumberofDays;

    short Curent = DayOfWeekOrder(1, Month ,Year);
    NumberofDays = NumberofDaysInYear(Month ,Year);

    printf("\n----------------%s------------------\n\n", NameMonth(Month).c_str());
    printf("   Sun  Mon  Tue  Wen  Thu  Fri  Sat\n");
    int i;
    for ( i = 0 ; i < Curent; i++)
        {
            printf("     ");
        }

    for(int j = 1; j <= NumberofDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n-------------------------------------\n");

}

void PrintCalander(short Year)
{
    printf("\n-------------------------------------\n");
    printf("               Calander - %d      ", Year)  ;
    printf("\n-------------------------------------\n");
    for(short i = 1; i <= 12; i++)
    {
        PrintMonthCalander(i, Year);
    }
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
    // PrintMonthCalander(1 , 2023);
    PrintCalander(ReadYear());
    system("pause>0");
}