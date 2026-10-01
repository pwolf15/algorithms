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

        // skip duplicates
        while (lo < hi && nums[lo] == nums[lo + 1]) ++lo;
        while (lo < hi && nums[hi] == nums[hi - 1]) --hi;
        ++lo;
        --hi;
      } else if (sum < 0) {
        // too low
        ++lo;
      } else {
        // too high
        --hi;
      }
    }
  }

  return triplets;
}
}  // namespace p0015

using Triplets = std::vector<std::vector<int>>;

Triplets normalized(Triplets t) {
  for (auto& v : t) std::sort(v.begin(), v.end());
  std::sort(t.begin(), t.end());
  return t;
}

TEST(P0015, ThreeSum) {
  struct Case {
    std::vector<int> nums;
    Triplets expected;
  };
  const Case cases[] = {
      {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
      {{0, 0, 0}, {{0, 0, 0}}},
      {{0, 0}, {}},
      {{}, {}},
      {{-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}}},
      {{-4, 2, 2, 2, 2}, {{-4, 2, 2}}},  // duplicate skipping
      {{-3, -1, 0, 1, 2, 3}, {{-3, 0, 3}, {-3, 1, 2}, {-1, 0, 1}}},
  };
  for (const auto& c : cases) {
    SCOPED_TRACE(testing::PrintToString(c.nums));
    EXPECT_EQ(normalized(p0015::threeSum(c.nums)), normalized(c.expected));
  }
}
