#include <gmock/gmock.h>

#include <string>
#include <unordered_set>

namespace p0003 {
int lengthOfLongestSubstring(std::string s) {
  std::unordered_set<char> window;

  int best = 0, left = 0;
  for (int right = 0; right < static_cast<int>(s.size()); ++right) {
    while (window.contains(s[right])) {
      window.erase(s[left++]);
    }
    best = std::max(best, right - left + 1);
    window.insert(s[right]);
  }
  return best;
}
}  // namespace p0003

TEST(P0003, Basic) {
  EXPECT_EQ(p0003::lengthOfLongestSubstring("abcabcbb"), 3);
  EXPECT_EQ(p0003::lengthOfLongestSubstring("bbbbb"), 1);
  EXPECT_EQ(p0003::lengthOfLongestSubstring("pwwwkew"), 3);
  EXPECT_EQ(p0003::lengthOfLongestSubstring("baaabca"), 3);
}

TEST(P0003, CheckOnLoopExit) {
  EXPECT_EQ(p0003::lengthOfLongestSubstring("S"), 1);
}
