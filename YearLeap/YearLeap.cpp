#include <iostream>
#include <string>

using namespace std;

// bool IsLeapYear(short Year)
// {
//     if (Year % 400 == 0)
//     {
//         return true;
//     }
//     else if (Year % 100 == 0)
//     {
//         return false;
//     }
//     else if (Year % 4 == 0)
//     {
//         return true;
//     }
//     else 
//     {
//         return false;
//     }
// }

bool IsLeapYear( short Year )
{
    return (Year % 400 == 0 ) || (Year % 4 == 0 && Year !=0) ;
}

short ReadYear()
{
    short Year;
    cout << "Enter Your Year ? ";
    cin >> Year;
    return Year;
}

int main()
{
    short Year = ReadYear();
    if (IsLeapYear(Year))
    {
        cout << "\nyes ; year  [" << Year << "] is Leap year  \n";
    }
    else 
    {
        cout << "\nyes ; year [" << Year << "] is Leap year \n";
    }
    system("pause>0");
}