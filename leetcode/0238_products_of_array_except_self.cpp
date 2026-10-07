#include <gmock/gmock.h>

#include <vector>

namespace p0238 {
std::vector<int> productExceptSelf(const std::vector<int>& nums) {
  int n = static_cast<int>(nums.size());
  std::vector<int> out(n, 1);
  for (int i = 1; i < n; ++i) out[i] = out[i - 1] * nums[i - 1];
  int suffix = 1;
  for (int i = n - 1; i >= 0; --i) {
    out[i] *= suffix;
    suffix *= nums[i];
  }
  return out;
}
}  // namespace p0238

TEST(P0238, Basic) {
  EXPECT_EQ(p0238::productExceptSelf({1, 2, 4, 6}), std::vector<int>({48, 24, 12, 8}));
  EXPECT_EQ(p0238::productExceptSelf({-1, 0, 1, 2, 3}), std::vector<int>({0, -6, 0, 0, 0}));
  EXPECT_EQ(p0238::productExceptSelf({0, 0}), std::vector<int>({0, 0}));
}
