#include <gmock/gmock.h>

#include <string>
#include <unordered_map>
#include <vector>

namespace p0049 {
std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
  std::unordered_map<std::string, std::vector<std::string>> groups;
  for (const auto& s : strs) {
    std::string key = s;
    std::sort(key.begin(), key.end());
    groups[key].push_back(s);
  }
  std::vector<std::vector<std::string>> results;
  results.reserve(groups.size());
  for (auto& [_, group] : groups) results.push_back(std::move(group));
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
