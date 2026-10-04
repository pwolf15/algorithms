#include <gmock/gmock.h>

#include <string>
#include <unordered_map>
#include <vector>

namespace p0049 {
std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
  // per string in strs, map alpha to count
  std::vector<std::array<int, 26>> counts(strs.size());
  for (auto& count : counts) {
    count.fill(0);
  }
  for (int i = 0; i < static_cast<int>(strs.size()); ++i) {
    for (const char c : strs[i]) {
      counts[i][c - 'a']++;
    }
  }

  // get unique counts
  std::vector<int> unique_counts;
  std::unordered_map<int, std::vector<int>> groups;
  for (int i = 0; i < static_cast<int>(counts.size()); ++i) {
    // compare to existing in unique_counts;
    bool match_found = false;
    for (int j = 0; j < static_cast<int>(unique_counts.size()); ++j) {
      // look for match, else add
      int match = j;
      for (int k = 0; k < 26; ++k) {
        if (counts[i][k] != counts[unique_counts[j]][k]) {
          match = -1;
          break;
        }
      }
      if (match == j) {
        groups[unique_counts[j]].push_back(i);
        match_found = true;
        break;
      }
    }
    if (!match_found) {
      unique_counts.push_back(i);
      groups[i].push_back(i);
    }
  }

  std::vector<std::vector<std::string>> results(unique_counts.size());
  for (int i = 0; i < static_cast<int>(unique_counts.size()); ++i) {
    auto& group = groups[unique_counts[i]];
    for (int j = 0; j < static_cast<int>(group.size()); ++j) {
      results[i].push_back(strs[group[j]]);
    }
  }
  return results;
}
}  // namespace p0049

using Anagrams = std::vector<std::vector<std::string>>;

Anagrams normalized(Anagrams a) {
  for (auto& v : a) {
    std::sort(v.begin(), v.end());
  }
  std::sort(a.begin(), a.end());
  return a;
}

TEST(P0049, Basic) {
  struct Case {
    std::vector<std::string> strs;
    Anagrams expected;
  };
  const Case cases[] = {{{""}, {{""}}},
                        {{"a"}, {{"a"}}},
                        {{"eat", "tea", "tan", "ate", "nat", "bat"},
                         {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}}};
  for (const auto& c : cases) {
    SCOPED_TRACE(testing::PrintToString(c.strs));
    EXPECT_EQ(normalized(p0049::groupAnagrams(c.strs)), normalized(c.expected));
  }
}
