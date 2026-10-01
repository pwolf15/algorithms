#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

namespace p0015 {
std::vector<std::vector<int>> threeSum(const std::vector<int>& nums_input) {
  std::vector<std::vector<int>> triplets;

  // sort nums
  std::vector<int> nums = nums_input;
  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
    if (nums[i] > 0) break;  // positive elements, sum cannot be zero

    if (i && nums[i] == nums[i - 1]) continue;

    int lo = i + 1, hi = static_cast<int>(nums.size()) - 1;
    while (lo < hi) {
      int sum = nums[i] + nums[lo] + nums[hi];
      if (sum == 0) {
        triplets.push_back({nums[i], nums[lo], nums[hi]});

        while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
        while (lo < hi && nums[hi] == nums[hi - 1]) hi--;
        ++lo;
        --hi;
      } else if (sum < 0) {
        // too low
        lo++;
      } else {
        // too high
        hi--;
      }
    }
  }

  return triplets;
}
}  // namespace p0015

TEST(P0015, ThreeSum) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  EXPECT_THAT(p0015::threeSum(nums),
              testing::UnorderedElementsAre(testing::UnorderedElementsAre(-1, -1, 2),
                                            testing::UnorderedElementsAre(-1, 0, 1)));
  nums = {0, 0, 0};
  EXPECT_THAT(p0015::threeSum(nums),
              testing::UnorderedElementsAre(testing::UnorderedElementsAre(0, 0, 0)));

  nums = {0, 0};
  EXPECT_THAT(p0015::threeSum(nums), testing::UnorderedElementsAre());

  nums = {-2, 0, 1, 1, 2};
  EXPECT_THAT(p0015::threeSum(nums),
              testing::UnorderedElementsAre(testing::UnorderedElementsAre(-2, 0, 2),
                                            testing::UnorderedElementsAre(-2, 1, 1)));

  nums = {-4, 2, 2, 2, 2};
  EXPECT_THAT(p0015::threeSum(nums),
              testing::UnorderedElementsAre(testing::UnorderedElementsAre(-4, 2, 2)));
  nums = {-3, -1, 0, 1, 2, 3};
  EXPECT_THAT(p0015::threeSum(nums),
              testing::UnorderedElementsAre(testing::UnorderedElementsAre(-3, 0, 3),
                                            testing::UnorderedElementsAre(-3, 1, 2),
                                            testing::UnorderedElementsAre(-1, 0, 1)));
}
