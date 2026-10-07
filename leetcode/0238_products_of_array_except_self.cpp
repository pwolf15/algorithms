#include <gmock/gmock.h>

#include <vector>

namespace p0238 {
std::vector<int> productExceptSelf(const std::vector<int>& nums) {
  std::vector<int> prefix_products(nums.size()), suffix_products(nums.size());

  // prefices
  prefix_products[0] = 1;

  for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
    prefix_products[i] = nums[i - 1] * prefix_products[i - 1];
  }

  // suffices
  suffix_products[static_cast<int>(nums.size()) - 1] = 1;
  for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
    suffix_products[i] = nums[i + 1] * suffix_products[i + 1];
  }

  std::vector<int> products;
  products.reserve(nums.size());
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    products.push_back(prefix_products[i] * suffix_products[i]);
  }
  return products;
}
}  // namespace p0238

TEST(P0238, Basic) {
  EXPECT_EQ(p0238::productExceptSelf({1, 2, 4, 6}), std::vector<int>({48, 24, 12, 8}));
  EXPECT_EQ(p0238::productExceptSelf({-1, 0, 1, 2, 3}), std::vector<int>({0, -6, 0, 0, 0}));
  EXPECT_EQ(p0238::productExceptSelf({0, 0}), std::vector<int>({0, 0}));
}
