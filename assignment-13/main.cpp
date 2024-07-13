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
};
struct Candidate {
  Puzzle candidate;
  int parent_candidate;
};
enum Direction {
  north, south, west, east
};

void output_field(const Field &field) {
  // Precondition
  assert(true);
  // Post-condition
  // Outputs the given puzzle field to the console
  for (auto &i: field) {
    for (Cell j: i)
      cout << j << " ";
    cout << endl;
  }
}

Field read_field(const string &challenge_filename) {
  // Precondition
  assert(true);
  // Post-condition
  // Reads puzzle from given file

  ifstream input(challenge_filename);
  Field field;
  string line;
  while (getline(input, line)) {
    Row row = {line.begin(), line.end()};
    field.push_back(row);
  }
  return field;
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
  return p1.flamingo == p2.flamingo && p1.field == p2.field;
}

bool puzzle_solved(Puzzle puzzle) {
  // Precondition
  assert(true);
  // Post-condition
  // Returns whether the puzzle is solved or not
  return puzzle.field[puzzle.flamingo.y][puzzle.flamingo.x] == 'x';
}

bool puzzle_solved(const Field &field, Position arbitrary_position) {
  // Precondition
  assert(true);
  // Post-condition
  // Returns whether the puzzle is solved or not
  return field[arbitrary_position.y][arbitrary_position.x] == 'x';
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
      while (!puzzle_solved(puzzle.field, {x, y})) {
        if (!position_in_field(puzzle.field, {x, y - 1})) {
          return false;
        } else if (puzzle.field[y - 1][x] == 'r') {
          return true;
        }
        y--;
      }
      return true;
    case south:
      while (!puzzle_solved(puzzle.field, {x, y})) {
        if (!position_in_field(puzzle.field, {x, y + 1})) {
          return false;
        } else if (puzzle.field[y + 1][x] == 'r') {
          return true;
        }
        y++;
      }
      return true;
    case west:
      while (!puzzle_solved(puzzle.field, {x, y})) {
        if (!position_in_field(puzzle.field, {x - 1, y})) {
          return false;
        } else if (puzzle.field[y][x - 1] == 'r') {
          return true;
        }
        x--;
      }
      return true;
    case east:
      while (!puzzle_solved(puzzle.field, {x, y})) {
        if (!position_in_field(puzzle.field, {x + 1, y})) {
          return false;
        } else if (puzzle.field[y][x + 1] == 'r') {
          return true;
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

Position find_flamingo(Field field) {
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition

  for (int row = 0; row < static_cast<int>(size(field)); ++row) {
    for (int col = 0; col < static_cast<int>(size(field[row])); ++col) {
      if (field[row][col] == 'f' || field[row][col] == 'F') {
        return {col, row};
      }
    }
  }
  return {};
}

int breadth_first(Field &field) {
  // Precondition
  // TODO: Write precondition
  assert(true);
  // Post-condition
  // TODO: Write post-condition

  Position flamingo = find_flamingo(field);
  Puzzle puzzle = {field, flamingo};

  int i = 0;
  vector<Candidate> c = {{puzzle, -1}};

  while (i < static_cast<int>(size(c)) && !puzzle_solved(c[i].candidate)) {
    Puzzle p = c[i].candidate;
    if (hits_rock_or_rescue(p, north)) {
      tries(c, i, north);
    }
    if (hits_rock_or_rescue(p, south)) {
      tries(c, i, south);
    }
    if (hits_rock_or_rescue(p, west)) {
      tries(c, i, west);
    }
    if (hits_rock_or_rescue(p, east)) {
      tries(c, i, east);
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
  Field field = read_field("challenge.1.3steps.txt");
  Position flamingo = find_flamingo(field);
  Puzzle puzzle = {field, flamingo};
  output_field(puzzle.field);

  if (hits_rock_or_rescue(puzzle, north)) {
    puzzle = slide(puzzle, north);
  }
  if (hits_rock_or_rescue(puzzle, east)) {
    puzzle = slide(puzzle, east);
  }
  if (hits_rock_or_rescue(puzzle, south)) {
    puzzle = slide(puzzle, south);
  }
  cout << endl;
  output_field(puzzle.field);
  return 0;
}

#endif