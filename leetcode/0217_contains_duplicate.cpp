#include <gmock/gmock.h>

#include <unordered_set>

namespace p0217 {
bool containsDuplicate(const std::vector<int>& nums) {
  std::unordered_set<int> unique_nums;
  for (int num : nums) {
    if (unique_nums.contains(num)) {
      return true;
    }

    unique_nums.insert(num);
  }
  return false;
}
}  // namespace p0217

TEST(P0217, Basic) {
  EXPECT_EQ(p0217::containsDuplicate({1, 2, 3, 1}), true);
  EXPECT_EQ(p0217::containsDuplicate({1, 2, 3, 4}), false);
  EXPECT_EQ(p0217::containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}), true);
}
