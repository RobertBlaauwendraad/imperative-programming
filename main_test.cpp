#include "main.cpp"
#include "gtest/gtest.h"

// TODO: Write correct tests
TEST(all_prices_positive, negative_price) {
  Gift gift = {.price= -100};
  EXPECT_EQ(all_prices_positive({gift}), false);
}

TEST(all_prices_positive, positive_price) {
  Gift gift = {.price= 100};
  EXPECT_EQ(all_prices_positive({gift}), true);
}

//TEST(gifts_test, zero_budget) {
//  EXPECT_EQ({}, 0), 0);
//}
//
//TEST(gifts_test, empty_wishlist) {
//  EXPECT_EQ(gifts({}, 3000), 3000);
//}