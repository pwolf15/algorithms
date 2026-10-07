#include <gmock/gmock.h>

#include <vector>

namespace p0238 {
std::vector<int> productExceptSelf(const std::vector<int>& nums) {
  int product = 1, num_zeros = 0;
  for (int num : nums) {
    if (!num) {
      num_zeros++;
      continue;
    }
    product *= num;
  }

  std::vector<int> products;
  products.reserve(nums.size());
  for (int num : nums) {
    if (!num && num_zeros == 1) {
      products.push_back(product);
    } else if (num && num_zeros) {
      products.push_back(0);
    } else if (num_zeros >= 2) {
      products.push_back(0);
    } else {
      products.push_back(product / num);
    }
  }
  return products;
}
}  // namespace p0238

TEST(P0238, Basic) {
  EXPECT_EQ(p0238::productExceptSelf({1, 2, 4, 6}), std::vector<int>({48, 24, 12, 8}));
  EXPECT_EQ(p0238::productExceptSelf({-1, 0, 1, 2, 3}), std::vector<int>({0, -6, 0, 0, 0}));
  EXPECT_EQ(p0238::productExceptSelf({0, 0}), std::vector<int>({0, 0}));
}
