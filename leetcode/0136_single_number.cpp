#include <gmock/gmock.h>

namespace p0136 {
int singleNumber(const std::vector<int>& nums) {
  int result = 0;
  for (const auto& num : nums) {
    result ^= num;
  }
  return result;
}
}  // namespace p0136

TEST(P0136, Basic) {
  EXPECT_EQ(p0136::singleNumber({2, 2, 1}), 1);
  EXPECT_EQ(p0136::singleNumber({4, 1, 2, 1, 2}), 4);
  EXPECT_EQ(p0136::singleNumber({1}), 1);
}
