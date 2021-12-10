#include <iostream>
#include <cassert>     /* assert */
#include <vector>
#include <string>
using namespace std;

int gifts(vector<string> wishlist, int budget) {
  // Precondition
  assert(budget >= 0);
  // Post-condition
  // Returns remaining budget after recursively "buying" gifts from the given wishlist

  // Base cases
  if (budget == 0 || wishlist.empty()) {
    return budget;
  }

  // TODO: Write algorithm
  return budget;
}

#ifndef TESTING
int main()
{
  return 0;
}
#endif