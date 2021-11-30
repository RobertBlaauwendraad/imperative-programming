#include "main.cpp"
#include "gtest/gtest.h"
#include "cmath"

TEST(power, naive_power_recursive)
{
    for(int i=0; i<10; i++)
    {
        int base = rand()%10;
        int exponent = rand()%5;
        EXPECT_EQ(naive_power(base, exponent), pow(base, exponent));
    }
}

TEST(power, power_recursive)
{
    for(int i=0; i<10; i++)
    {
        int base = rand()%10;
        int exponent = rand()%5;
        EXPECT_EQ(power(base, exponent), pow(base, exponent));
    }
}

/* UNCOMMENT THIS SECTION IF YOU HAVE DEVELOPED FUNCTION palindrome1
TEST(palindrome, palindrome_1)
{
    EXPECT_TRUE(palindrome1("", 0, 0));
    EXPECT_TRUE(palindrome1("a", 0, 0));
    EXPECT_TRUE(palindrome1("otto", 0, 3));
    EXPECT_FALSE(palindrome1("Otto", 0, 3));
    EXPECT_FALSE(palindrome1("Oo", 0, 1));
    EXPECT_FALSE(palindrome1("Imperative. Programming", 0, 22));
    EXPECT_FALSE(palindrome1("Madam, I'm Adam.", 0, 15));
}
END OF COMMENT */

/* UNCOMMENT THIS SECTION IF YOU HAVE DEVELOPED FUNCTION palindrome2
TEST(palindrome, palindrome_2)
{
    EXPECT_TRUE(palindrome2("", 0, 0));
    EXPECT_TRUE(palindrome2("a", 0, 0));
    EXPECT_TRUE(palindrome2("otto", 0, 3));
    EXPECT_TRUE(palindrome2("Otto", 0, 3));
    EXPECT_TRUE(palindrome2("Oo", 0, 1));
    EXPECT_FALSE(palindrome2("Imperative. Programming", 0, 22));
    EXPECT_FALSE(palindrome2("Madam, I'm Adam.", 0, 15));
}
END OF COMMENT */

/* UNCOMMENT THIS SECTION IF YOU HAVE DEVELOPED FUNCTION palindrome3
TEST(palindrome, palindrome_3)
{
    EXPECT_TRUE(palindrome3("", 0, 0));
    EXPECT_TRUE(palindrome3("a", 0, 0));
    EXPECT_TRUE(palindrome3("otto", 0, 3));
    EXPECT_TRUE(palindrome3("Otto", 0, 3));
    EXPECT_TRUE(palindrome2("Oo", 0, 1));
    EXPECT_FALSE(palindrome2("Imperative. Programming", 0, 22));
    EXPECT_TRUE(palindrome3("Madam, I'm Adam.", 0, 15));
}
END OF COMMENT */

/* UNCOMMENT THIS SECTION IF YOU HAVE DEVELOPED FUNCTION match_chars
TEST(matchCharacters, match_characters)
{
    EXPECT_TRUE(match_chars("abc", 0, "it is a bag of cards", 0));
    EXPECT_FALSE(match_chars("abc", 0, "it is a bag of books", 0));
    EXPECT_FALSE(match_chars("abc", 0, "it is a classy bag", 0));
    EXPECT_TRUE(match_chars("perm", 0, "imperative programming", 0));
    EXPECT_FALSE(match_chars("prime", 0, "imperative programming", 0));
}
END OF COMMENT */