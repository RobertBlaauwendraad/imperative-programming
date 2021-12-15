#include "main.cpp"
#include "gtest/gtest.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <cassert>
#include <iostream>

TEST(bfs, challenge0)
{
    vector< vector<char> > field = {
        {'.','.','.','.','.','.'},
        {'.','.','.','.','.','.'},
        {'.','.','.','.','.','.'},
        {'.','.','.','.','.','.'},
        {'.','.','.','.','.','F'}
    };
    EXPECT_EQ(breadth_first(field), 0);
}

TEST(bfs, challenge1)
{
    vector< vector<char> > field = {
        {'.','.','.','.','r','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','r','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','f','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','x','.','.'}
    };
    EXPECT_EQ(breadth_first(field), 3);
}

TEST(bfs, challenge2)
{
    vector< vector<char> > field = {
        {'.','.','.','.','.','r','.'},
        {'r','.','.','.','.','.','.'},
        {'r','.','f','.','.','.','r'},
        {'.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.'},
        {'.','.','.','.','r','.','.'},
        {'.','r','.','x','.','.','.'}
    };
    EXPECT_EQ(breadth_first(field), 4);
}

TEST(bfs, challenge3)
{
    vector< vector<char> > field = {
        {'r','r','r','r','r','r','r'},
        {'.','.','.','.','.','.','r'},
        {'.','r','r','r','.','.','.'},
        {'.','.','.','x','.','.','.'},
        {'.','.','.','.','.','.','.'},
        {'.','r','.','.','.','.','.'},
        {'f','.','.','.','.','r','.'}
    };
    EXPECT_EQ(breadth_first(field), 6);
}

TEST(bfs, challenge4)
{
    vector< vector<char> > field = {
        {'.','.','.','.','.','.','.','.','.','.','.','r','.','.'},
        {'r','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.','r','.','.','.'},
        {'.','.','r','.','.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','x','.','r','.','.','.','.','.'},
        {'.','.','.','.','.','r','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','f','.','.','.','.','r','.'},
        {'.','.','.','.','.','.','.','.','.','r','.','.','.','.'},
        {'.','.','.','r','.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.','.','r','.','r'},
        {'.','r','.','.','.','.','.','.','.','.','.','.','.','.'}
    };
    EXPECT_EQ(breadth_first(field), 12);
}

/* UNCOMMENT THIS SECTION IF YOU HAVE DEVELOPED FUNCTION depth_first
TEST(dfs, challenge0)
{
    vector< vector<char> > board = {
        {'.','.','.','.','.','.'},
        {'.','.','.','.','.','.'},
        {'.','.','.','.','.','.'},
        {'.','.','.','.','.','.'},
        {'.','.','.','.','.','F'}
    };
    EXPECT_EQ(depth_first(board), 0);
}

TEST(dfs, challenge1)
{
    vector< vector<char> > board = {
        {'.','.','.','.','r','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','r','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','f','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','x','.','.'}
    };
    EXPECT_EQ(depth_first(board), 3);
}

TEST(dfs, challenge2)
{
    vector< vector<char> > board = {
        {'.','.','.','.','.','r','.'},
        {'r','.','.','.','.','.','.'},
        {'r','.','f','.','.','.','r'},
        {'.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.'},
        {'.','.','.','.','r','.','.'},
        {'.','r','.','x','.','.','.'}
    };
    EXPECT_EQ(depth_first(board), 4);
}

TEST(dfs, challenge3)
{
    vector< vector<char> > board = {
        {'r','r','r','r','r','r','r'},
        {'.','.','.','.','.','.','r'},
        {'.','r','r','r','.','.','.'},
        {'.','.','.','x','.','.','.'},
        {'.','.','.','.','.','.','.'},
        {'.','r','.','.','.','.','.'},
        {'f','.','.','.','.','r','.'}
    };
    EXPECT_EQ(depth_first(board), 6);
}

TEST(dfs, challenge4)
{
    vector< vector<char> > board = {
        {'.','.','.','.','.','.','.','.','.','.','.','r','.','.'},
        {'r','.','.','.','.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.','r','.','.','.'},
        {'.','.','r','.','.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','x','.','r','.','.','.','.','.'},
        {'.','.','.','.','.','r','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','f','.','.','.','.','r','.'},
        {'.','.','.','.','.','.','.','.','.','r','.','.','.','.'},
        {'.','.','.','r','.','.','.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.','.','.','.','r','.','r'},
        {'.','r','.','.','.','.','.','.','.','.','.','.','.','.'}
    };
    EXPECT_EQ(depth_first(board), 12);
}
END OF COMMENT */