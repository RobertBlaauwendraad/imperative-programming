#include <iostream>
#include <cassert>

using namespace std;

int naive_power(int x, int n) 
{
    // Precondition
    assert(n >= 0);
    // Postcondition
    // Recursively calculate x^n

    if (n == 0)
        return 1;
    return x * naive_power(x, n - 1);
}

int power(int x, int n) 
{
    // Precondition
    assert(n >= 0);
    // Postcondition
    // Recursively calculate x^n with time complexity O(log n)

    int pow;
    if (n == 0)
        return 1;

    pow = power(x, n / 2);
    if (n % 2 == 0)
        return pow * pow;
    else
        return x * pow * pow;
}

bool palindrome1 (string text, int i, int j) 
{
    // Precondition
    assert(i >= 0 && j <= static_cast<int>(text.length()));
    // Postcondition
    // Recursively check if text is a palindrome

    if(i >= j)
        return true;
    else if(text.length() < 2 )
        return true;
    else if (text[i] != text[j])
        return false;
    else
        return palindrome1(text, i+1, j-1);
}

// bool palindrome2 (string text, int i, int j) 
// {
//     // Precondition
//     assert(true);
//     // Postcondition
//     //
// }

// bool palindrome3 (string text, int i, int j) 
// {
//     // Precondition
//     assert(true);
//     // Postcondition
//     //
// }

// bool match_chars(string chars, int i, string source, int j) 
// {
//     // Precondition
//     assert(true);
//     // Postcondition
//     //
// }

#ifndef TESTING
int main()
{
    return 0;
}
#endif