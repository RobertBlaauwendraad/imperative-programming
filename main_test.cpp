#include "main.cpp"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

// Note that the following array declarations only initialize 12x12 grids.
// The ROWS and COLUMNS constants have values 42 and 62 however.
// In this case the 'missing' values will be 'zero-initialized'.
// This means they will have the value 0, which corresponds to the enum member Dead.
// Effectively we only describe a portion of the top-left part of the universe to test with.
// The rest of the universe will implicitly be made up of dead cells.
Cell glider0[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Live, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell glider1[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Live, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell glider2[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Live, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell glider3[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell glider4[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell emptyCell[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

void arrayCopy(Cell original [ROWS][COLUMNS], Cell copy [ROWS][COLUMNS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            copy[i][j] = original[i][j];
        }
    }
}

bool generationMatch(Cell generation [ROWS][COLUMNS], Cell reference [ROWS][COLUMNS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            if(generation[i][j] != reference[i][j])
                return false;
        }
    }
    return true;
}

TEST(next_gen, glider_0)
{
    Cell now [ROWS][COLUMNS];
    Cell next [ROWS][COLUMNS];
    Cell next_reference [ROWS][COLUMNS];
    arrayCopy(glider0, now);
    arrayCopy(emptyCell, next);
    arrayCopy(glider1, next_reference);
    next_generation(now, next);
    EXPECT_TRUE(generationMatch(next, next_reference));
}

TEST(next_gen, glider_1)
{
    Cell now [ROWS][COLUMNS];
    Cell next [ROWS][COLUMNS];
    Cell next_reference [ROWS][COLUMNS];
    arrayCopy(glider1, now);
    arrayCopy(emptyCell, next);
    arrayCopy(glider2, next_reference);
    next_generation(now, next);
    EXPECT_TRUE(generationMatch(next, next_reference));
}

TEST(next_gen, glider_2)
{
    Cell now [ROWS][COLUMNS];
    Cell next [ROWS][COLUMNS];
    Cell next_reference [ROWS][COLUMNS];
    arrayCopy(glider2, now);
    arrayCopy(emptyCell, next);
    arrayCopy(glider3, next_reference);
    next_generation(now, next);
    EXPECT_TRUE(generationMatch(next, next_reference));
}

TEST(next_gen, glider_3)
{
    Cell now [ROWS][COLUMNS];
    Cell next [ROWS][COLUMNS];
    Cell next_reference [ROWS][COLUMNS];
    arrayCopy(glider3, now);
    arrayCopy(emptyCell, next);
    arrayCopy(glider4, next_reference);
    next_generation(now, next);
    EXPECT_TRUE(generationMatch(next, next_reference));
}
