#include <gmock/gmock.h>

#include <queue>
#include <unordered_map>
#include <vector>

namespace p0347 {
std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
  // get count for each unique element
  std::unordered_map<int, int> counts;
  for (int num : nums) {
    counts[num]++;
  }

  // create min-heap
  auto cmp = [](const auto& a, const auto& b) { return a.first > b.first; };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> heap;
  for (const auto& [v, c] : counts) {
    heap.push({c, v});

    // pop when count(elements) > k
    if (static_cast<int>(heap.size()) > k) heap.pop();
  }

  std::vector<int> results;
  while (!heap.empty()) {
    results.push_back(heap.top().second);
    heap.pop();
  }
  return results;
}
}  // namespace p0347

TEST(P0347, Basic) {
  EXPECT_THAT(p0347::topKFrequent({1, 2, 2, 3, 3, 3}, 2), testing::UnorderedElementsAre(3, 2));
  EXPECT_THAT(p0347::topKFrequent({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2),
              testing::UnorderedElementsAre(1, 2));
}
