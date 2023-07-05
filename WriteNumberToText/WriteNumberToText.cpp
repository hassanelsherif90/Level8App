#include <iostream>
#include <string>

using namespace std;

int ReadNumber()
{
    int Number;
    cout << "\nEnter Your Number ? ";
    cin >> Number;
    return Number;
}

string NumberToText(int Number)
{
    if(Number == 0)
    {
        return "";
    }

    if(Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One", "Two", "Three", "Four", "Five",
                                "Six", "Seven", "Eight", "Nine", "Ten", 
                                "Ealven", "twelve", "Thirteen", "Fourteen", 
                                "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                                "Nineteen" };
            return arr[Number] + " ";
        }
    if(Number >= 20 && Number <= 99)
    {
        string arr[ ] = {"", "", "Twinty", "Thitry", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty"};
        return arr[Number  / 10] + " " + NumberToText(Number % 10) ;
    }

    if (Number >= 100 && Number <= 199)
    {
        return ("One Hundred "  + NumberToText(Number % 100)) ;
    }

    if (Number >= 200 && Number <= 999)
    {
        return (NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100));
    }

    if (Number >= 1000 && Number <= 1999)
    {
        return (NumberToText(Number / 1000) + "Thousend " + NumberToText(Number % 1000));
    }
    
    if (Number >= 2000 && Number <= 999999)
    {
        return (NumberToText(Number / 1000) + "Thousend " + NumberToText(Number % 1000));
    }

    if (Number >= 1000000 && Number <= 1999999)
    {
        return (NumberToText(Number / 1000000) + "Milion " + NumberToText(Number % 1000000));
    }
    
    if (Number >= 2000000 && Number <= 9999999)
    {
        return (NumberToText(Number / 1000000) + "Milions " + NumberToText(Number % 1000000));
    }

    if (Number >= 10000000 && Number <= 19999999)
    {
        return (NumberToText(Number / 10000000) + "Billion " + NumberToText(Number % 10000000));
    }
    else 
    {
        return (NumberToText(Number / 10000000) + "Billion " + NumberToText(Number % 10000000));
    }

}

int main()
{
    int Number = ReadNumber();
    cout << NumberToText (Number) << endl;
    system("pause>0");
}