#include <gmock/gmock.h>

#include <vector>

namespace p0121 {
int maxProfit(const std::vector<int>& prices) {
  int min_price = prices[0], max_profit = 0;
  for (auto price : prices) {
    min_price = std::min(price, min_price);
    max_profit = std::max(price - min_price, max_profit);
  }
  return max_profit;
}
}  // namespace p0121

TEST(P0121, Basic) {
  EXPECT_EQ(p0121::maxProfit({7, 1, 5, 3, 6, 4}), 5);
  EXPECT_EQ(p0121::maxProfit({7, 6, 4, 3, 1}), 0);
  EXPECT_EQ(p0121::maxProfit({10, 1, 5, 6, 7, 1}), 6);
  EXPECT_EQ(p0121::maxProfit({10, 8, 7, 5, 2}), 0);
  EXPECT_EQ(p0121::maxProfit({2, 4, 1}), 2);
}
