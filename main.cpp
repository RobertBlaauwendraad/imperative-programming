#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

enum Cell {Dead=0, Live};                         // a cell is either Dead or Live (we use the fact that dead = 0 and live = 1)

const char DEAD             = '.' ;               // the presentation of a dead cell (both on file and screen)
const char LIVE             = '*' ;               // the presentation of a live cell (both on file and screen)
const int NO_OF_ROWS        = 40 ;                // the number of rows (height) of the universe (both on file and screen)
const int NO_OF_COLUMNS     = 60 ;                // the number of columns (width) of the universe (both on file and screen)
const int ROWS              = NO_OF_ROWS    + 2 ; // the number of rows in a universe array, including the 'frame' of dead cells
const int COLUMNS           = NO_OF_COLUMNS + 2 ; // the number of columns in a universe array, including the 'frame' of dead cells
const string FILENAME = "build/glider0.txt";

//  Part 1: setting the scene
bool read_universe_file (ifstream& inputfile, Cell universe [ROWS][COLUMNS])
{
    // Precondition:
    assert(inputfile.is_open());
    /* Post-condition:
    * Get universe from extern file and put it in universe array.
    */

    char cell;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLUMNS - 1)
            {
                universe[i][j] = (Cell)0;
            }
        }
    }

    for (int i = 1; i <= NO_OF_ROWS; i++)
    {
        for (int j = 1; j <= NO_OF_COLUMNS; j++)
        {
            inputfile.get(cell);
            if (cell == LIVE)
            {
                universe[i][j] = (Cell)1;
            } else if (cell == DEAD)
            {
                universe[i][j] = (Cell)0;
            } else {
                j--;
            }
        }
    }
    return false;
}

void show_universe (Cell universe [ROWS][COLUMNS])
{
    // Precondition:
    assert(true);
    /* Post-condition:
    * Show the universe array in the console.
    */
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (universe[i][j] == (Cell)1)
            {
                // cout << '(' << i << ',' << j << ')';
                cout << '*';
            } else if (universe[i][j] == (Cell)0) {
                cout << '.';
            }
        }
        cout << endl;
    }
}

//  Part 2: the next generation
void next_generation (Cell now [ROWS][COLUMNS], Cell next [ROWS][COLUMNS])
{
    // pre-conditions, post-conditions, implementation
}

#ifndef TESTING
int main ()
{
    Cell universe[ROWS][COLUMNS];
    ifstream inputfile(FILENAME);
    if(inputfile.fail()) {
        cout << FILENAME << " could not be opened\n";
        return 1;
    }

    read_universe_file(inputfile, universe);
    
    show_universe(universe);
    return 0;
}
#endif
