#include <iostream>

using namespace std;

enum Month
{
  January = 1, February, March, April, May, June,
  July, August, September, October, November, December
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
    int days;
    
    switch (month)
    {
      case Month::January:
        days = 31;
        break;
      case Month::February:
        if (is_leap)
        {
          days = 29;
        } else {
          days = 28;
        }
        break;
      case Month::March:
        days = 31;
        break;
      case Month::April:
        days = 30;
        break;
      case Month::May:
        days = 31;
        break;
      case Month::June:
        days = 30;
        break;
      case Month::July:
        days = 31;
        break;
      case Month::August:
        days = 31;
        break;
      case Month::September:
        days = 30;
        break;
      case Month::October:
        days = 31;
        break;
      case Month::November:
        days = 30;
        break;
      case Month::December:
        days = 31;
        break;
    }
    return days;
}

/********************************************************************
  Assignment part 2: Holy days based on Easter
********************************************************************/
string calculate_date(int easter_day, Month easter_month, int year, int days_difference) 
{
  int new_day = easter_day;
  int new_month = easter_month;

  for (int i = 0; i < abs(days_difference); i++)
  {
    if (days_difference < 0) {
      if (new_day > 1) {
        new_day--;
      } else {
        new_month = (Month)new_month - 1;
        new_day = number_of_days_in_month(year, (Month)new_month);
      }
    } else {
      if (new_day < number_of_days_in_month(year, (Month)new_month))
      {
        new_day++;
      } else {
        new_month = (Month)new_month + 1;
        new_day = 1;
      }
    }
  }
  string new_date = to_string(new_day) + "-" + to_string(new_month);
  return new_date;
}

string show_carnival(int easter_day, Month easter_month, int year)
{
  // 7 weeks before easter, ending on Tuesday.
  return calculate_date(easter_day, easter_month, year, -49);
}

string show_good_friday(int easter_day, Month easter_month, int year)
{
  // Friday before easter
  return calculate_date(easter_day, easter_month, year, -2);
}

string show_easter(int easter_day, Month easter_month, int year)
{
  // Easter itself
  return to_string(easter_day) + "-" + to_string(easter_month);
}

string show_whitsuntide(int easter_day, Month easter_month, int year)
{
  // 7 weeks after easter
  return calculate_date(easter_day, easter_month, year, 49);
}

string show_ascension_day(int easter_day, Month easter_month, int year)
{
  // 10 days before whitsuntide
  return calculate_date(easter_day, easter_month, year, 39);
}

void show_holy_days (int year)
{
  int easter_day = calculate_easter_day(year);
  Month easter_month = calculate_easter_month(year);
  
  string carnival_date = show_carnival(easter_day, easter_month, year);
  string good_friday_date = show_good_friday(easter_day, easter_month, year);
  string easter_date = show_easter(easter_day, easter_month, year);
  string ascension_day_date = show_ascension_day(easter_day, easter_month, year);
  string whitsuntide_date = show_whitsuntide(easter_day, easter_month, year);

  cout << "Carnival: " << carnival_date << endl
       << "Good Friday: " << good_friday_date << endl
       << "Easter: " << easter_date << endl
       << "Ascension Day: " << ascension_day_date << endl
       << "Whitsuntide: " << whitsuntide_date << endl;
}

#ifndef TESTING
int main() {
  int year;

  cout << "Enter a year (yyyy) to get the holy days in a day-month format:"<< endl;
  cin >> year;
  show_holy_days(year);
  return 0;
}
#endif
