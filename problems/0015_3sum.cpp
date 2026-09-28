#include <gtest/gtest.h>
#include <vector>


namespace p0015 {
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  return {};
}
}

TEST(P0015, ThreeSum) {

  auto triplets_equal = [](std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b) {

    if (a.size() != b.size()) return false;

    for (auto& vec: a) {
      std::sort(vec.begin(), vec.end());
    }
    for (auto& vec: b) {
      std::sort(vec.begin(), vec.end());
    }
    
    for (const auto& vec1: a) {
      bool match = false;
      for (const auto& vec2: b) {
        if (vec1[0] == vec2[0] && vec1[1] == vec2[1] && vec1[2] == vec2[2]) 
        {
          match = true;
          break;
        }    
      }
      if (!match) return false;
    }
    return true;
  };
  std::vector<std::vector<int>> expected = {{-1,-1,2},{-1,0,1}};
  std::vector<int> nums = {-1,0,1,2,-1,-4};
  auto result = p0015::threeSum(nums);
  EXPECT_TRUE(triplets_equal(expected, expected));
}
