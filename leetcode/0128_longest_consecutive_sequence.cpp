#include <gmock/gmock.h>

#include <unordered_set>
#include <vector>

namespace p0128 {
int longestConsecutive(const std::vector<int>& nums) {
  // track seen elements
  std::unordered_set<int> seen(nums.begin(), nums.end());

  int max_len = 0;

  for (int x : seen) {
    // if x - 1 exists, walk from x - 1, not x
    if (seen.count(x - 1)) continue;

    // walk sequence
    int target = x + 1;
    int cur_len = 1;
    while (seen.count(target)) {
      cur_len++;
      target++;
    }
    max_len = std::max(max_len, cur_len);
  }
  return max_len;
}
}  // namespace p0128

TEST(P0128, Basic) {
  EXPECT_EQ(p0128::longestConsecutive({100, 4, 200, 1, 3, 2}), 4);
  EXPECT_EQ(p0128::longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}), 9);
  EXPECT_EQ(p0128::longestConsecutive({1, 0, 1, 2}), 3);
}
