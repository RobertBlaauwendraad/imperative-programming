#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <cassert>
#include <iostream>

using namespace std;

void output_puzzle(const vector<vector<char>>& field) {
  // Precondition
  assert(true);
  // Post-condition
  // Outputs the given field to the console

  for (auto & i : field) {
    for (char j : i)
      cout << j << " ";
    cout << endl;
  }
}

vector<vector<char>> read_puzzle(const string& challenge_filename) {
  // Precondition
  assert(true);
  // Post-condition
  // Return the field read from the given file

  ifstream input(challenge_filename);
  vector<vector<char>> field;
  string line;
  while (getline(input, line)) {
    vector<char> row = {line.begin(), line.end()};
    field.push_back(row);
  }
  return field;
}

//int breadth_first(vector<vector<char>>& field)
//{
//    //Implement this function
//}
//
//int depth_first(vector<vector<char>>& field)
//{
//    //Implement this function
//}

#ifndef TESTING
int main()
{
  vector<vector<char>> field = read_puzzle("challenge.0.0steps.txt");
  output_puzzle(field);
  return 0;
}
#endif