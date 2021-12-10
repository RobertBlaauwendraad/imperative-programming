#include "main.cpp"
#include "gtest/gtest.h"

// TODO: Write correct tests
TEST(gifts_test, zero_budget) {
  EXPECT_EQ(gifts({"Playstation 5"}, 0), 0);
}

TEST(gifts_test, empty_wishlist) {
  EXPECT_EQ(gifts({}, 3000), 3000);
}