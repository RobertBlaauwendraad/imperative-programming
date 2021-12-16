#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <cassert>
#include <iostream>

using namespace std;

typedef char Cell;
typedef vector<Cell> Row;
typedef vector<Row> Field;
struct Position {
  int x, y;
};
struct Puzzle {
  Field field;
  Position flamingo;
  Position finish;
};
struct Candidate {
  Puzzle candidate;
  int parent_candidate;
};
enum Direction {
  north, south, west, east
};

void output_puzzle(const Puzzle &puzzle) {
  // Precondition
  assert(true);
  // Post-condition
  // Outputs the given puzzle field to the console
  for (auto &i: puzzle.field) {
    for (Cell j: i)
      cout << j << " ";
    cout << endl;
  }
}

Puzzle read_puzzle(const string &challenge_filename) {
  // Precondition
  assert(true);
  // Post-condition
  // Reads puzzle from given file

  ifstream input(challenge_filename);
  Puzzle puzzle;
  string line;
  int y = 0;
  while (getline(input, line)) {
    Row row = {line.begin(), line.end()};
    for (int x = 0; x < static_cast<int>(row.size()); ++x) {
      if (row[x] == 'x') {
        puzzle.finish = {x, y};
      } else if (row[x] == 'f' || row[x] == 'F') {
        puzzle.flamingo = {x, y};
      }
    }
    puzzle.field.push_back(row);
    y++;
  }
  return puzzle;
}

bool position_in_field(Field f, Position p) {
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition

  if (p.x < 0 || p.y < 0 || p.x >= static_cast<int>(size(f[0])) || p.y >= static_cast<int>(size(f))) {
    return false;
  }
  return true;
}

bool puzzle_solved(Puzzle puzzle) {
  // Precondition
  assert(true);
  // Post-condition
  // Returns whether the puzzle is solved or not
  return puzzle.field[puzzle.flamingo.y][puzzle.flamingo.x] == 'x';
}

bool operator==(Position p1, Position p2) {
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition
  return p1.x == p2.x && p1.y == p2.y;
}

bool operator==(const Puzzle &p1, const Puzzle &p2) {
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition
  return p1.flamingo == p2.flamingo && p1.finish == p2.finish && p1.field == p2.field;
}

bool puzzle_solved(const Puzzle &puzzle, Position arbitrary_position) {
  // Precondition
  assert(true);
  // Post-condition
  // Returns whether the puzzle is solved or not
  return arbitrary_position == puzzle.finish;
}

bool hits_rock_or_rescue(Puzzle puzzle, Direction direction) {
  // Precondition
  assert(true);
  // Post-condition
  // Checks if sliding in a direction will eventually hit a rock or the rescue location

  // Create new int variables for readability
  int x = puzzle.flamingo.x;
  int y = puzzle.flamingo.y;

  switch (direction) {
    case north:
      while (!puzzle_solved(puzzle, {x, y})) {
        if (puzzle.field[y - 1][x] == 'r') {
          return true;
        } else if (!position_in_field(puzzle.field, {x, y - 1})) {
          return false;
        }
        y--;
      }
      return true;
    case south:
      cout << puzzle.field[5][7] << endl;
      while (!puzzle_solved(puzzle, {x, y})) {
        if (puzzle.field[y + 1][x] == 'r') {
          return true;
        } else if (!position_in_field(puzzle.field, {x, y + 1})) {
          return false;
        }
        y++;
      }
      return true;
    case west:
      while (!puzzle_solved(puzzle, {x, y})) {
        if (puzzle.field[y][x - 1] == 'r') {
          return true;
        } else if (!position_in_field(puzzle.field, {x - 1, y})) {
          return false;
        }
        x--;
      }
      return true;
    case east:
      while (!puzzle_solved(puzzle, {x, y})) {
        if (puzzle.field[y][x + 1] == 'r') {
          return true;
        } else if (!position_in_field(puzzle.field, {x + 1, y})) {
          return false;
        }
        x++;
      }
      return true;
  }
}

Puzzle slide(Puzzle puzzle, Direction direction) {
  // Precondition
  assert(hits_rock_or_rescue(puzzle, direction));
  // Post-condition
  // Slide in direction until rock is hit or rescue location is reached

  // Set old flamingo position to .
  puzzle.field[puzzle.flamingo.y][puzzle.flamingo.x] = '.';

  // While the puzzle is not solved slide in the given direction until a rock is reached;
  switch (direction) {
    case north:
      while (!puzzle_solved(puzzle)) {
        if (puzzle.field[puzzle.flamingo.y - 1][puzzle.flamingo.x] == 'r') {
          break;
        }
        puzzle.flamingo.y--;
      }
      break;
    case south:
      while (!puzzle_solved(puzzle)) {
        if (puzzle.field[puzzle.flamingo.y + 1][puzzle.flamingo.x] == 'r') {
          break;
        }
        puzzle.flamingo.y++;
      }
      break;
    case west:
      while (!puzzle_solved(puzzle)) {
        if (puzzle.field[puzzle.flamingo.y][puzzle.flamingo.x - 1] == 'r') {
          break;
        }
        puzzle.flamingo.x--;
      }
      break;
    case east:
      while (!puzzle_solved(puzzle)) {
        if (puzzle.field[puzzle.flamingo.y][puzzle.flamingo.x + 1] == 'r') {
          break;
        }
        puzzle.flamingo.x++;
      }
      break;
  }

  // Update current position to f
  puzzle.field[puzzle.flamingo.y][puzzle.flamingo.x] = 'f';
  return puzzle;
}

bool puzzle_present(vector<Candidate> &c, int i, Puzzle p) {
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition

  for (int j = 0; j < i; ++j) {
    if (c[j].candidate == p) {
      return true;
    }
  }
  return false;
}

void tries(vector<Candidate> &c, int i, Direction direction) {
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition

  Puzzle p = c[i].candidate;
  Puzzle new_p = slide(p, direction);
  if (!puzzle_present(c, i, new_p)) {
    Candidate new_c = {new_p, i};
    c.push_back(new_c);
  }
}

int breadth_first(Puzzle start) {
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition

  int i = 0;
  vector<Candidate> c = {{start, -1}};

  while (i < static_cast<int>(size(c)) && !puzzle_solved(c[i].candidate)) {
    Puzzle p = c[i].candidate;
    if (hits_rock_or_rescue(p, north)) {

    }
    if (hits_rock_or_rescue(p, south)) {

    }
    if (hits_rock_or_rescue(p, west)) {

    }
    if (hits_rock_or_rescue(p, east)) {

    }
    i++;
  }
  if (i < static_cast<int>(size(c))) {
    return i;
  } else {
    return 0;
  }
}

//int depth_first(Field& field)
//{
//    //Implement this function
//}

#ifndef TESTING

int main() {
  Puzzle puzzle = read_puzzle("challenge.1.3steps.txt");
  output_puzzle(puzzle);

  if (hits_rock_or_rescue(puzzle, north)) {
    puzzle = slide(puzzle, north);
  }
  if (hits_rock_or_rescue(puzzle, east)) {
    puzzle = slide(puzzle, north);
  }
  if (hits_rock_or_rescue(puzzle, south)) {
    puzzle = slide(puzzle, north);
  }
  cout << endl;
  output_puzzle(puzzle);
  return 0;
}

#endif