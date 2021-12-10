#include "main.cpp"
#include "gtest/gtest.h"

TEST(all_prices_positive_test, negative_price) {
  Gift gift = {.price= -100};
  EXPECT_EQ(all_prices_positive({gift}), false);
}

TEST(all_prices_positive_test, positive_price) {
  Gift gift = {.price= 100};
  EXPECT_EQ(all_prices_positive({gift}), true);
}

TEST(gifts_test, zero_budget) {
  Gift gift = {.price = 100};
  EXPECT_EQ(gifts({gift}, 0, 0), 0);
}

TEST(gifts_test, empty_wishlist) {
  EXPECT_EQ(gifts({}, 0, 3000), 3000);
}

TEST(gifts_test, too_expensive_single_gift) {
  vector<Gift> wishlist = {{2000, "Playstation 5"}};
  int budget = 1000;
  EXPECT_EQ(gifts(wishlist, 0, budget), budget);
}

TEST(gifts_test, single_gift) {
  vector<Gift> wishlist = {{2000, "Playstation 5"}};
  int budget = 4000;
  EXPECT_EQ(gifts(wishlist, 0, budget), 2000);
}

TEST(gifts_test, multiple_gifts) {
  vector<Gift> wishlist = {
      {2000, "Playstation 5"},
      {1000, "Xbox One"},
      {500, "Wii U"}
  };
  int budget = 4000;
  EXPECT_EQ(gifts(wishlist, 0, budget), 500);
}

TEST(gifts_test, multiple_gifts_exit_early) {
  vector<Gift> wishlist = {
      {2000, "Playstation 5"},
      {1000, "Xbox One"},
      {2000, "Wii U"}
  };
  int budget = 4000;
  EXPECT_EQ(gifts(wishlist, 0, budget), 1000);
}