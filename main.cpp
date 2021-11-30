#include <iostream>
#include <cassert>

using namespace std;

int naive_power(int x, int n) 
{
    // Precondition
    assert(n >= 0);
    // Postcondition
    // Recursively calculate x^n
    if (n == 0) {
        return 1;
    }
    return x * naive_power(x, n - 1);
}

int power(int x, int n) 
{
    // Precondition
    assert(n >= 0);
    // Postcondition
    //
}

// bool palindrome1 (string text, int i, int j) 
// {
//     // Precondition
//     assert(true);
//     // Postcondition
//     //
// }

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