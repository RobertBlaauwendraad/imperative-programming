#include <iostream>
#include <cassert>
#include <vector>

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
    // Recursively check if text is a case-sensitive palindrome

    if (j == 0 || i == static_cast<int>(text.length()) - 1)
        return true;
    else if(text.length() < 2 )
        return true;
    else if (text[i] != text[j])
        return false;
    else
        return palindrome1(text, i+1, j-1);
}

bool palindrome2 (string text, int i, int j) 
{
    // Precondition
    assert(i >= 0 && j <= static_cast<int>(text.length()));
    // Postcondition
    // Recursively check if text is a case-insensitive palindrome

    if (j == 0 || i == static_cast<int>(text.length()) - 1)
        return true;
    else if (text.length() < 2)
        return true;
    else if (tolower(text[i]) != tolower(text[j]))
        return false;
    else
        return palindrome2(text, i + 1, j - 1);
}

bool palindrome3 (string text, int i, int j) 
{
    // Precondition
    assert(i >= 0 && j <= static_cast<int>(text.length()));
    // Postcondition
    // Recursively check if text is a case-and-space-insensitive palindrome

    if(j == 0 || i == static_cast<int>(text.length()) - 1)
        return true;
    else if (
        text[i] == ' ' ||
        text[i] == '.' ||
        text[i] == ',' ||
        text[i] == ':' ||
        text[i] == ';' ||
        text[i] == '\'' ||
        text[i] == '!' ||
        text[i] == '?' ||
        text[i] == '-'
    )
        return palindrome3(text, i+1, j);
    else if (
        text[j] == ' ' ||
        text[j] == '.' ||
        text[j] == ',' ||
        text[j] == ':' ||
        text[j] == ';' ||
        text[j] == '\'' ||
        text[j] == '!' ||
        text[j] == '?' ||
        text[j] == '-'
    )
        return palindrome3(text, i, j-1);
    else if (text.size() < 2)
        return true;
    else if (tolower(text[i]) != tolower(text[j]))
        return false;
    else 
        return palindrome3(text, i+1, j-1);
}

bool match_chars(string chars, int i, string source, int j) 
{
    // Precondition
    assert(i >= 0 && j >= 0);
    // Postcondition
    // Checks if characters match in a string with skipping characters

    if(i == chars.length())
        return true;
    else if (j == source.length())
        return false;
    else if (chars[i] == source[j])
        return match_chars(chars, i+1, source, j);
    else
        return match_chars(chars, i, source, j+1);
}

#ifndef TESTING
int main()
{
    return 0;
}
#endif