#include <gmock/gmock.h>

#include <unordered_map>
#include <vector>

namespace p0347 {
std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
  // get count for each unique element
  std::unordered_map<int, int> counts;
  for (int num : nums) {
    counts[num]++;
  }

  std::vector<int> keys;
  keys.reserve(counts.size());
  for (const auto& [v, c] : counts) keys.push_back(v);

  // partial sort top-k
  auto cmp = [&](int a, int b) {
    int ca = counts.at(a), cb = counts.at(b);
    return ca != cb ? ca > cb : a < b;
  };
  std::partial_sort(keys.begin(), keys.begin() + k, keys.end(), cmp);

  // return first k elements
  keys.resize(k);
  return keys;
}
}  // namespace p0347

TEST(P0347, Basic) {
  EXPECT_EQ(p0347::topKFrequent({1, 2, 2, 3, 3, 3}, 2), std::vector<int>({3, 2}));
  EXPECT_EQ(p0347::topKFrequent({1, 2, 1, 2, 1, 2, 3, 1, 3, 2}, 2), std::vector<int>({1, 2}));
}
