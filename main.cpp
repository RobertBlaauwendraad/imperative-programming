#include <iostream>

using namespace std;

enum Month
{
  January = 31, February = 1, March = 31, April = 30, May = 31, June = 30,
  July = 31, August = 31, September = 30, October = 31, November = 30, December = 31
};

/*  The function easter_base uses the Meeus/Jones/Butcher formula to compute
  the number that is used to determine on which month (easter_month below)
  and day (easter_day below) Easter is in the given year.
*/
int easter_base (int year)
{
  const int A = year % 19;
  const int B = year / 100;
  const int C = year % 100;
  const int D = B / 4;
  const int E = B % 4;
  const int F = (B + 8) / 25;
  const int G = (B - F + 1) / 3;
  const int H = (19 * A + B - D - G + 15) % 30;
  const int I = C / 4;
  const int K = C % 4;
  const int L = (32 + 2 * E + 2 * I - H - K) % 7;
  const int M = (A + 11 * H + 22 * L) / 451;
  return H + L - 7 * M + 114;
}

/*  The result of easter_year is the day number of the month in which Easter occurs in
  the given year.
*/
int calculate_easter_day (int year)
{
  return (easter_base (year) % 31) + 1;
}

/*  The result of easter_month is the month in which Easter occurs in the given year.
*/
Month calculate_easter_month (int year)
{
  return static_cast<Month> (easter_base (year) / 31);
}


/********************************************************************
  Assignment part 1: Leap years
********************************************************************/
bool is_leap_year (int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                return true; 
            }
        } else {
            return true;
        }
    }
    return false;
}

int number_of_days_in_month (int year, Month month) {
    bool is_leap = is_leap_year(year); 

    if(month == Month::February){
        if(is_leap){
            return 29;
        } else {
            return 28;
        }
    }

    return month;
}

/********************************************************************
  Assignment part 2: Holy days based on Easter
********************************************************************/
string show_carnival(int easter_day, Month easter_month, int year)
{
  // implement this function
}

string show_good_friday(int easter_day, Month easter_month, int year)
{
  // implement this function
}

string show_easter(int easter_day, Month easter_month, int year)
{
  // implement this function
}

string show_whitsuntide(int easter_day, Month easter_month, int year)
{
  // implement this function
}

string show_ascension_day(int easter_day, Month easter_month, int year)
{
  // implement this function
}

void show_holy_days (int year)
{
  // implement this function
}

#ifndef TESTING
int main() {
    
    cout << Month::March << endl;

    return 0;
        
}
#endif
