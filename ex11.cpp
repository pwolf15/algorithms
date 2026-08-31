#include <iostream>
#include <vector>

int main() {
  auto maxArea = [](std::vector<int>& height) {
   int max_vol = 0;
   for (int i = 0; i < height.size() - 1; ++i) {
    for (int j = i; j < height.size(); ++j) {
      int area_height = std::min(height[i], height[j]);
      int distance = j - i;
      max_vol = std::max(max_vol, distance * area_height);
    }
   }
   return max_vol;
  };

  std::vector<int> heights{1,8,6,2,5,4,8,3,7};
  std::cout << maxArea(heights) << "\n";
  heights = {1,1};
  std::cout << maxArea(heights) << "\n";
  return 0;
}
