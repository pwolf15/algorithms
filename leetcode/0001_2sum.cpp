#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace p0001 {
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
  std::unordered_map<int, int> seen;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    auto it = seen.find(target - nums[i]);
    if (it != seen.end()) {
      return {it->second, i};
    }

    seen[nums[i]] = i;
  }
  return {};
}
}  // namespace p0001

TEST(P0001, Basic) {
  auto sorted = [](std::vector<int> v) {
    std::sort(v.begin(), v.end());
    return v;
  };

  EXPECT_THAT(p0001::twoSum({2, 7, 11, 15}, 9), testing::ElementsAre(0, 1));
  EXPECT_THAT(p0001::twoSum({3, 2, 4}, 6), testing::ElementsAre(1, 2));
  EXPECT_THAT(p0001::twoSum({3, 3}, 6), testing::ElementsAre(0, 1));
  EXPECT_THAT(p0001::twoSum({-3, 4, 3, 90}, 0), testing::ElementsAre(0, 2));
}
