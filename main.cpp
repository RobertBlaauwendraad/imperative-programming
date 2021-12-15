#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <cassert>
#include <iostream>

using namespace std;

typedef char Cell;
struct Position {
  int col, row;
};
struct Puzzle {
  vector<vector<Cell>> board;
  Position finish;
};
struct Candidate {
  Puzzle candidate;
  int parent_candidate;
};

void output_puzzle(const Puzzle& puzzle) {
  // Precondition
  assert(true);
  // Post-condition
  // Outputs the given puzzle board to the console
  for (auto & i : puzzle.board) {
    for (char j : i)
      cout << j << " ";
    cout << endl;
  }
}

Puzzle read_puzzle(const string& challenge_filename) {
  // Precondition
  assert(true);
  // Post-condition
  // Reads puzzle from given file

  ifstream input(challenge_filename);
  Puzzle puzzle;
  string line;

  int y = 0;
  while (getline(input, line)) {
    vector<char> row = {line.begin(), line.end()};
    for (int x = 0; x < static_cast<int>(row.size()); ++x) {
      if (row[x] == 'x') {
        puzzle.finish = {x, y};
      }
    }
    puzzle.board.push_back(row);
    y++;
  }
  return puzzle;
}

int breadth_first(vector<vector<char>>& field)
{
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition

  int current_attempt = 0;

  return current_attempt;
}

//int depth_first(vector<vector<char>>& board)
//{
//    //Implement this function
//}

#ifndef TESTING
int main()
{
  Puzzle puzzle = read_puzzle("challenge.1.3steps.txt");
  output_puzzle(puzzle);
  return 0;
}
#endif