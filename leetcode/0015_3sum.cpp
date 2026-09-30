#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

namespace p0015 {
std::vector<std::vector<int>> threeSum(const std::vector<int>& nums_input) {
  std::vector<std::vector<int>> results;
  std::vector<int> nums;
  std::copy(nums_input.begin(), nums_input.end(), std::back_insert_iterator(nums));
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    // skip duplicates
    if (i && (nums[i] == nums[i - 1])) continue;

    // positive - no more matches
    if (nums[i] > 0) break;

    int lo = i + 1, hi = nums.size() - 1;
    while (lo < hi) {
      // skip duplicates
      if (lo > i + 1 && nums[lo] == nums[lo - 1]) {
        lo++;
        continue;
      }
      if (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]) {
        hi--;
        continue;
      }

      int sum = nums[hi] + nums[lo] + nums[i];
      if (sum < 0) {
        lo++;
      } else if (sum > 0) {
        hi--;
      } else {
        std::vector<int> new_result{nums[i], nums[hi], nums[lo]};
        results.emplace_back(new_result);
        hi--;
        lo++;
      }
    }
  }

  return results;
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

  nums = {-3, -1, 0, 1, 2, 3};
  EXPECT_THAT(p0015::threeSum(nums),
              testing::UnorderedElementsAre(testing::UnorderedElementsAre(-3, 0, 3),
                                            testing::UnorderedElementsAre(-3, 1, 2),
                                            testing::UnorderedElementsAre(-1, 0, 1)));
}
