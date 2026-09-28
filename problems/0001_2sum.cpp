#include <gtest/gtest.h>

#include <unordered_map>
#include <set>

namespace p0001 {
std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, std::set<int>> lookup;
  
  // map each element to its set of indices
  for (size_t i = 0; i < nums.size(); ++i) {
    lookup[nums[i]].insert(i);
  }
  
  // iterate over nums
  // search lookup for target - nums[i]a
  std::vector<int> result = {};
  for (size_t i = 0; i < nums.size(); ++i) {
    auto indices = lookup[target-nums[i]];
    
    if (indices.empty() || (nums[i] == target - nums[i] && indices.size() == 1)) {
      // not a match  
      continue;
    } else if (nums[i] == target - nums[i]) {
      result.push_back(*indices.begin());
      result.push_back(*indices.rbegin());
      return result;
    } else {
      result.push_back(*lookup[nums[i]].begin());
      result.push_back(*lookup[target-nums[i]].begin());
      return result;
    }
  }
  return result;
}
}

TEST(P0001, Basic) {
  auto compare_outputs = [](std::vector<int> a, std::vector<int> b) {
    if (a.size() != 2 || b.size() != 2) return false;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    for (size_t i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) return false;
    }
    return true;
  };  

  std::vector<int> nums = {2,7,11,15};
  std::vector<int> exp = {0,1};
  int target = 9;

  EXPECT_TRUE(compare_outputs(p0001::twoSum(nums, target), exp));

  nums = {3,2,4}, target = 6, exp = {1,2};
  EXPECT_TRUE(compare_outputs(p0001::twoSum(nums, target), exp));

  nums = {3,3}, target = 6, exp = {0,1};
  EXPECT_TRUE(compare_outputs(p0001::twoSum(nums, target), exp));
}
