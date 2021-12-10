#include <iostream>
#include <cassert>     /* assert */
#include <vector>
#include <string>
using namespace std;

struct Gift {
  int price;
  string category;
  string name;
};

bool all_prices_positive(vector<Gift> wishlist) {
  // Precondition
  assert(true);
  // Post-condition
  // Checks whether all prices on wishlist are positive
  bool all_positive = true;
  for (int i = 0; i < static_cast<int>(size(wishlist)); i++) {
    if (wishlist[i].price < 0) {
      all_positive = false;
    }
  }
  return all_positive;
}

int gifts(vector<Gift> wishlist, int gift, int budget) {
  // Precondition
  assert(all_prices_positive(wishlist) && gift >= 0);
  // Post-condition
  // Returns remaining budget after recursively "buying" gifts from the given wishlist

  // Base cases
  if (budget == 0) {
    return 1;
  } else if (budget < 0 || gift >= static_cast<int>(size(wishlist))) {
    return 0;
  } else {
    int with_gift = gifts(wishlist, gift+1, budget - wishlist[gift].price);
    int without_gift = gifts(wishlist, gift+1, budget);
    return with_gift + without_gift;
  }
}

#ifndef TESTING
int main()
{
  return 0;
}
#endif