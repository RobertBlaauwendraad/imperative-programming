#include "main.cpp"
#include "gtest/gtest.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>

vector<Track> testDB = {{"Adele",                          "19",                          2008,1, "Daydreamer",                  "pop,debut album",                   { 3,40},"England"}
                       ,{"Adele",                          "19",                          2008,10,"My same",                     "pop,debut album",                   { 3,15},"England"}
                       ,{"Adele",                          "19",                          2008,11,"Tired",                       "pop,debut album",                   { 4,18},"England"}
                       ,{"Adele",                          "19",                          2008,12,"Hometown glory",              "pop,debut album",                   { 4,31},"England"}
                       ,{"Adele",                          "19",                          2008,2, "Best for last",               "pop,debut album",                   { 4,18},"England"}
                       ,{"Adele",                          "19",                          2008,3, "Chasing pavements",           "pop,debut album",                   { 3,30},"England"}
                       ,{"Adele",                          "19",                          2008,4, "Cold shoulder",               "pop,debut album",                   { 3,11},"England"}
                       ,{"Adele",                          "19",                          2008,5, "Crazy for you",               "pop,debut album",                   { 3,28},"England"}
                       ,{"Adele",                          "19",                          2008,6, "Melt my heart to stone",      "pop,debut album",                   { 3,23},"England"}
                       ,{"Adele",                          "19",                          2008,7, "First love",                  "pop,debut album",                   { 3,10},"England"}
                       ,{"Adele",                          "19",                          2008,8, "Right as rain",               "pop,debut album",                   { 3,17},"England"}
                       ,{"Adele",                          "19",                          2008,9, "Make you feel my love",       "pop,debut album",                   { 3,32},"England"}
                       ,{"Adele",                          "21",                          2011,1, "Rolling in the deep",         "pop",                               { 3,49},"England"}
                       ,{"Adele",                          "21",                          2011,10,"Lovesong",                    "pop",                               { 5,16},"England"}
                       ,{"Adele",                          "21",                          2011,11,"Someone like you",            "pop",                               { 4,47},"England"}
                       ,{"Adele",                          "21",                          2011,2, "Rumour has it",               "pop",                               { 3,43},"England"}
                       ,{"Adele",                          "21",                          2011,3, "Turning tables",              "pop",                               { 4,10},"England"}
                       ,{"Adele",                          "21",                          2011,4, "Don't you remember",          "pop",                               { 4, 3},"England"}
                       ,{"Adele",                          "21",                          2011,5, "Set fire to the rain",        "pop",                               { 4, 1},"England"}
                       ,{"Adele",                          "21",                          2011,6, "He won't go",                 "pop",                               { 4,37},"England"}
                       ,{"Adele",                          "21",                          2011,7, "Take it all",                 "pop",                               { 3,48},"England"}
                       ,{"Adele",                          "21",                          2011,8, "I'll be waiting",             "pop",                               { 4, 1},"England"}
                       ,{"Adele",                          "21",                          2011,9, "One and only",                "pop",                               { 5,48},"England"}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,1, "Call me star",                "alternative,rock",                  { 3,54},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,2, "El centro",                   "alternative,rock,instrumental",     { 8,25},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,3, "Dirt preachers",              "alternative,rock",                  { 3,44},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,4, "This is where it falls apart","alternative,rock",                  { 7, 2},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,5, "Mellowing",                   "alternative,instrumental",          { 3,11},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,6, "Open passageways",            "alternative,rock",                  { 3,14},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,7, "Instrumental 2 (welcome to the caveman future)"
                                                                                                                                ,"alternative,rock,instrumental",     { 2,33},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,8, "Talisman",                    "alternative,rock",                  { 6, 7},"U.S.A."}
                       ,{"All them witches",               "Dying surfer meets his maker",2015,9, "Blood and sand / milk and endless waters","alternative,rock",      { 7,20},"U.S.A."}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,1, "The sun roars into view",     "jazz,instrumental,experimental",    { 7,37},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was"  ,2015,2, "Won't be a thing to become",  "jazz,instrumental,experimental",    { 3,24},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,3, "In the vespers",              "jazz,instrumental,experimental",    { 6, 2},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,4, "And still they move",         "jazz,instrumental,experimental",    { 2,56},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,5, "With the dark hug of time",   "jazz,instrumental,experimental",    { 6,34},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,6, "The rest of us",              "jazz,instrumental,experimental",    { 6,30},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,7, "Never were the way she was",  "jazz,instrumental,experimental",    { 8,12},"U.S.A.,Canada"}
                       ,{"Colin Stetson and Sarah Neufeld","Never were the way she was",  2015,8, "Flight",                      "jazz,instrumental,experimental",    { 1,38},"U.S.A.,Canada"}
                       ,{"The decemberists",               "The tain",                    2005,1, "The tain (parts i-iv)",       "progressive,experimental,folk,rock",{18,35},"U.S.A."}
                       } ;

bool operator== (const Length& a, const Length& b)
{// Precondition:
    assert (0 <= a.minutes && 0 <= a.seconds && a.seconds < 60 && 0 <= b.minutes && 0 <= b.seconds && b.seconds < 60) ;
/*  Postcondition:
    Result is true only if a and b represent the same time length
*/
    return a.minutes == b.minutes && a.seconds == b.seconds;
}

bool operator== (const Track& a, const Track& b)
{// Precondition:
    assert (true);
/*  Postcondition:
    Result is true only if all fields of a and b are equal
*/
    return a.artist  == b.artist  &&
           a.cd      == b.cd      &&
           a.country == b.country &&
           a.tags    == b.tags    &&
           a.time    == b.time    &&
           a.title   == b.title   &&
           a.track   == b.track   &&
           a.year    == b.year;
}

TEST(operators, length_desktop)
{
    Length l1     = {42,55};
    Length l2     = { 3, 4};
    Length l3     = {24, 6};
    Length sum [] = {l1+l1, l1+l2, l1+l3
                    ,l2+l1, l2+l2, l2+l3
                    ,l3+l1, l3+l2, l3+l3
                    };
    Length res [] = {Length{85,50}
                    ,Length{45,59}
                    ,Length{67, 1}
                    ,Length{45,59}
                    ,Length{ 6, 8}
                    ,Length{27,10}
                    ,Length{67, 1}
                    ,Length{27,10}
                    ,Length{48,12}
                    };
    for (int i = 0 ; i < 9 ; i++)
        EXPECT_EQ (sum[i], res[i]);
}

TEST(operators, length_random)
{
    for(int i=0; i<10; i++)
    {
        int lengths[4] = {rand()%20, rand()%60, rand()%20, rand()%60};
        Length left = Length{lengths[0], lengths[1]};
        Length right = Length{lengths[2], lengths[3]};
        Length addition = left + right;
        EXPECT_EQ(addition.minutes*60+addition.seconds, (left.minutes+right.minutes)*60+left.seconds+right.seconds);
    }
}

TEST(commands, match_tracks1)
{
    string match = "my";
    int expected = 2;
    EXPECT_EQ(expected, match_tracks(testDB,match,false));
}

TEST(commands, match_tracks2)
{
    string match = "is";
    int expected = 2;
    EXPECT_EQ(expected, match_tracks(testDB,match,false));
}

TEST(commands, match_tracks3)
{
    string match = "and";
    int expected = 2;
    EXPECT_EQ(expected, match_tracks(testDB,match,false));
}

TEST(commands, match_artists1)
{
    string match = "A";
    int expected = 2;
    EXPECT_EQ(expected, match_artists(testDB,match,false));
}

TEST(commands, match_artists2)
{
    string match = "em";
    int expected = 2;
    EXPECT_EQ(expected, match_artists(testDB,match,false));
}

TEST(commands, match_artists3)
{
    string match = "ts";
    int expected = 2;
    EXPECT_EQ(expected, match_artists(testDB,match,false));
}

TEST(commands, match_cds1)
{
    string match = "A";
    int expected = 3;
    EXPECT_EQ(expected, match_cds(testDB,match,false));
}

TEST(commands, match_cds2)
{
    string match = "em";
    int expected = 2;
    EXPECT_EQ(expected, match_cds(testDB,match,false));
}

TEST(commands, match_cds3)
{
    string match = "ts";
    int expected = 2;
    EXPECT_EQ(expected, match_cds(testDB,match,false));
}

TEST(commands, number_of_cds)
{
    int expected = 5;
    EXPECT_EQ(expected, number_of_cds(testDB));
}

TEST(read, read_db_with_zero_tracks)
{
    vector<Track> the_tracks;
    EXPECT_EQ(read_tracks ("TracksZeroTrackDB.txt", the_tracks, false), 0);
}

TEST(read, read_db_with_one_track)
{
    vector<Track> the_tracks;
    EXPECT_EQ(read_tracks ("TracksOneTrackDB.txt", the_tracks, false), 1);
}

TEST(read, read_testDB)
{
    vector<Track> the_tracks;
    EXPECT_EQ(read_tracks ("TracksTestDB.txt", the_tracks, false), 41);
    EXPECT_EQ(the_tracks,testDB);
}

TEST(read, read_MusicDB)
{
    vector<Track> the_tracks;
    EXPECT_EQ(read_tracks ("Tracks.txt", the_tracks, false), 6868);
}
