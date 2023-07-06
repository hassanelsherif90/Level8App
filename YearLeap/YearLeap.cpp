#include <iostream>
#include <string>

using namespace std;


bool IsYearLeap(short Year)
{
    if (Year % 400 == 0)
    {
        return true;
    }
    else if (Year % 100 == 0)
    {
        return false;
    }
    else if (Year % 4 == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }

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
    if (IsYearLeap(Year))
    {
        cout << "\nyes ; year  [" << Year << "] is year Leap \n";
    }
    else 
    {
        cout << "\nyes ; year [" << Year << "] is year Leap \n";
    }
    system("pause>0");
}