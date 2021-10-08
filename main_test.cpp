#include "main.cpp"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>

using namespace std;

TEST(part_one, rotateChar)
{
  for (int i = 33; i < 127; i++)
  {
    int random = rand() % 50;
    EXPECT_EQ (rotate_char (rotate_char (i, random, Encrypt), random, Decrypt), i);
  }
}

/* This code is used to unit test functions that operate on streams. You do not
   need to understand what it is doing. */
struct OTP_predef_enc : public testing::Test{
  ifstream infile; 
  ofstream outfile;
  string input = "test.txt";
  stringstream buffer;
  stringstream buffercheck;
  void SetUp ()
  {
    if (infile.is_open ())
    {
      infile.close ();
    }
    if (outfile.is_open ())
    {
      outfile.clear ();
      outfile.close ();
    }
    infile.open (input.c_str ());
  };

  void TearDown ()
  {
    infile.close ();
    outfile.clear ();
    outfile.close ();
  }
};

/* UNCOMMENT THIS SECTION IF YOU HAVE DEVELOPED FUNCTION use_OTP
TEST_F(OTP_predef_enc, use_OTP_1)
{
    string valueout = "output1.txt";
    outfile.open(valueout.c_str());
    use_OTP(infile, outfile, Encrypt, 1);
    outfile.close();

    ifstream output, outputcheck;
    output.open(valueout.c_str());
    outputcheck.open("test_encrypted_with_1.txt");
    bool match = true;
    char rotated;
    char reference;
    while(output.get(rotated))
    {
        outputcheck.get(reference);
        if(rotated != reference){
            match = false;
        }
    }
    EXPECT_TRUE(match);
}

TEST_F (OTP_predef_enc, use_OTP_42)
{
    string valueout = "output42.txt";
    outfile.open(valueout.c_str());
    use_OTP(infile, outfile, Encrypt, 42);
    outfile.close();

    ifstream output, outputcheck;
    output.open(valueout.c_str());
    outputcheck.open("test_encrypted_with_42.txt");
    bool match = true;
    char rotated;
    char reference;
    while(output.get(rotated))
    {
        outputcheck.get(reference);
        if(rotated != reference){
            match = false;
        }
    }
    EXPECT_TRUE(match);
}

TEST_F (OTP_predef_enc, use_OTP_96)
{
    string valueout = "output96.txt";
    outfile.open(valueout.c_str());
    use_OTP(infile, outfile, Encrypt, 96);
    outfile.close();

    ifstream output, outputcheck;
    output.open(valueout.c_str());
    outputcheck.open("test_encrypted_with_96.txt");
    bool match = true;
    char rotated;
    char reference;
    while(output.get(rotated))
    {
        outputcheck.get(reference);
        if(rotated != reference){
            match = false;
        }
    }
    EXPECT_TRUE(match);
}

TEST_F(OTP_predef_enc, use_OTP_65535)
{
    string valueout = "output65535.txt";
    outfile.open(valueout.c_str());
    use_OTP(infile, outfile, Encrypt, 65535);
    outfile.close();

    ifstream output, outputcheck;
    output.open(valueout.c_str());
    outputcheck.open("test_encrypted_with_65535.txt");
    bool match = true;
    char rotated;
    char reference;
    while(output.get(rotated))
    {
        outputcheck.get(reference);
        if(rotated != reference){
            match = false;
        }
    }
    EXPECT_TRUE(match);
}
END OF COMMENT */
