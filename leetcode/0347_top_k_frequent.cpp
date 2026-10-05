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

  std::vector<std::vector<int>> buckets(nums.size() + 1);
  for (const auto& [v, c] : counts) {
    buckets[c].push_back(v);
  }

  std::vector<int> results;
  results.reserve(k);
  for (int i = static_cast<int>(nums.size()); i > 0; --i) {
    if (static_cast<int>(results.size()) == k) return results;
    results.insert(results.end(), buckets[i].begin(), buckets[i].end());
  }
  return results;
}
}  // namespace p0347

TEST(P0347, Basic) {
  EXPECT_THAT(p0347::topKFrequent({1, 2, 2, 3, 3, 3}, 2), testing::UnorderedElementsAre(3, 2));
  EXPECT_THAT(p0347::topKFrequent({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2),
              testing::UnorderedElementsAre(1, 2));
}
