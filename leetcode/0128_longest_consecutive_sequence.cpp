#include <gmock/gmock.h>

#include <unordered_set>
#include <vector>

namespace p0128 {
int longestConsecutive(const std::vector<int>& nums) {
  std::unordered_set<int> num_map;
  int max_len = 0;

  for (int i = 0; i < static_cast<int>(nums.size()); ++i) num_map.insert(nums[i]);
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    int target = nums[i] + 1;
    int cur_len = 1;
    while (num_map.count(target)) {
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
