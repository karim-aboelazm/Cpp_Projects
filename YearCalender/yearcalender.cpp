#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/* 
skip() : This function is used to add spaces and 
make the output presentable in calender format.
*/
void skip (int i)
{
    while (i > 0)
    {
        cout << " "; 
        i --;
    }
}

/*
error() : This function is used to handle cases of 
incorrect values respective to the problem and stop 
the execution (eg month > 12 or month < 1)
*/ 
void error ()
{
    cout << "\nError. End procedure." << "\n";
    exit (-1);
}

/*
leap_year  : This function checks if the entered 
year is a leap year or not using the formula.
*/ 
bool leap_year (int year)
{
    return   ((year%4==0) && (year%100 !=0))||(year%400==0);
}

/*
start_day() : This function calculates and 
returns the start day of the year specified
*/ 
int  start_day(int year)
{
    int day_start;
    int x1, x2, x3;
    x1 = (year - 1)/ 4;
    x2 = (year - 1)/ 100;
    x3 = (year - 1)/ 400;
    day_start = (year + x1 - x2 + x3) % 7;
    return day_start;
}

/*
number_days_month() : The number of days depending on 
the month entered are calculated and returned by this function
*/ 
int number_days_month (int m, bool leap)
{
    if (m == 1) return(31);
    else if (m == 2) if (leap) return(29);else return(28);
    else if (m == 3) return(31);
    else if (m == 4) return(30);
    else if (m == 5) return(31);
    else if (m == 6) return(30);
    else if (m == 7) return(31);
    else if (m == 8) return(31);
    else if (m == 9) return(30);
    else if (m == 10) return(31);
    else if (m == 11) return(30);
    else if (m == 12) return(31);
    else error();
}

/*
print_month_name() : For presenting the 
calendar, this function prints the month name
*/ 
void print_month_name (int m)
{
    if      (m == 1 ) { skip(7); cout << "  January"   << "\n"; }
    else if (m == 2 ) { skip(7); cout << "  February"  << "\n"; }
    else if (m == 3 ) { skip(7); cout << "  March"     << "\n"; }
    else if (m == 4 ) { skip(7); cout << "  April"     << "\n"; }
    else if (m == 5 ) { skip(7); cout << "  May"       << "\n"; }
    else if (m == 6 ) { skip(7); cout << "  June"      << "\n"; }
    else if (m == 7 ) { skip(7); cout << "  July"      << "\n"; }
    else if (m == 8 ) { skip(7); cout << "  August"    << "\n"; }
    else if (m == 9 ) { skip(7); cout << "  September" << "\n"; } 
    else if (m == 10) { skip(7); cout << "  October"   << "\n"; }
    else if (m == 11) { skip(7); cout << "  November"  << "\n"; }
    else if (m == 12) { skip(7); cout << "  December"  << "\n"; }
    else error();

    cout << " Sa  Mo  Tu  We  Th  Fr  Su " <<"\n";
    cout << "____________________________" << "\n";
}

/*
print_month() : This function actually prints 
the date numbers below the month title for each month
*/ 
void print_month (int number_days, int &weekDay)
{
    int day = 1;

    while (day <= number_days)
    {
    cout << setw(2) << day << "  ";
    if (weekDay == 6)
    {
        cout << "\n";
        weekDay = 0;
    }
    else weekDay = weekDay + 1;
    day = day + 1;
    }
}

/*
Start() : This function actually Using All functions
in above to use looping 
*/ 
void Start(){
    int year, start_day_month, number_days, current_month = 1;
    bool leap;

    cout << "Enter the year : ";
    cin >>year;
    cout<<"\n";

    start_day_month=start_day(year);
    leap = leap_year(year);
    skip(9);

    cout << year << "\n";

    while (current_month <= 12)
    {
    number_days = number_days_month(current_month, leap);
    print_month_name(current_month);
    print_month(number_days, start_day_month);
    cout << "\n\n\n";
    current_month = current_month + 1;
    }
    cout << "\n";
}

int main ()
{
    while (true){
        Start();
    }   
}