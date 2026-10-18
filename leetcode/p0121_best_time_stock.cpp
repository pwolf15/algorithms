#include <gmock/gmock.h>

#include <vector>

namespace p0121 {
int maxProfit(const std::vector<int>& prices) {
  if (prices.size() <= 1) return 0;
  int buy = 0, sell = 0, num_days = static_cast<int>(prices.size());
  int max_profit = 0;
  while (sell < num_days) {
    if (buy == sell) {
      // buy day == sell day
      sell++;
    } else if (prices[buy] >= prices[sell]) {
      // buy_prices >= sell_price
      buy++;
    } else {
      // buy_price < sell_price
      max_profit = std::max(max_profit, prices[sell] - prices[buy]);
      sell++;
    }
  }
  return max_profit;
}
}  // namespace p0121

TEST(P0121, Basic) {
  EXPECT_EQ(p0121::maxProfit({7, 1, 5, 3, 6, 4}), 5);
  EXPECT_EQ(p0121::maxProfit({7, 6, 4, 3, 1}), 0);
  EXPECT_EQ(p0121::maxProfit({10, 1, 5, 6, 7, 1}), 6);
  EXPECT_EQ(p0121::maxProfit({10, 8, 7, 5, 2}), 0);
}
