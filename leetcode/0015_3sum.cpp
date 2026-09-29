#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

namespace p0015 {

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
  std::unordered_map<int, int> seen;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    auto it = seen.find(target - nums[i]);
    if (it != seen.end()) {
      return {i, it->second};
    }

    seen[nums[i]] = i;
  }
  return {};
}

std::vector<std::vector<int>> threeSum(const std::vector<int>& nums) {
  // for each element, run two sum
  std::vector<std::vector<int>> results;
  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    const auto& result = twoSum(nums, -nums[i]);
    if (!result.empty()) results.push_back({nums[i], nums[result[0]], nums[result[1]]});
  }
  return results;
}
}  // namespace p0015

TEST(P0015, TwoSum) {
  EXPECT_THAT(p0015::twoSum({3, 2, 4}, 5), testing::UnorderedElementsAre(0, 1));
}

TEST(P0015, ThreeSum) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  EXPECT_THAT(p0015::threeSum(nums),
              testing::UnorderedElementsAre(testing::UnorderedElementsAre(-1, -1, 2),
                                            testing::UnorderedElementsAre(-1, 0, 1)));
}
