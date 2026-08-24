#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {

#if SOL1
  for (int i = 0; i < nums.size() - 1; ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
       if ((nums[i] + nums[j]) == target) return {i,j};
    }
  }
#else
  std::unordered_map<int, int> seen; 
  for (int i = 0; i < (int)nums.size(); ++i) {
    auto it = seen.find(target - nums[i]);
    if (it != seen.end()) return {it->second, i};
    seen[nums[i]] = i;
  }
#endif
  return {};
}

int main() {
  std::vector<int> nums = {2,7,11,15};
  int target = 9;

  auto print_result = [](std::vector<int> result) {
    if (result.size() != 2) return;
    std::cout << "a: " << result[0] << ", b: " << result[1] << "\n";
  };
  print_result(twoSum(nums, target));

  nums = {3,2,4}, target = 6;
  print_result(twoSum(nums, target));

  nums = {3,3}, target = 6;
  print_result(twoSum(nums, target));

  return 0;
}
