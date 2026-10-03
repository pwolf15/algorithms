#include <gmock/gmock.h>

#include <string>
#include <unordered_set>

namespace p0003 {
int lengthOfLongestSubstring(std::string s) {
  std::unordered_set<char> char_set;

  int max_seen = 0;

  // keep left, right iterators
  int left = 0, right = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    if (char_set.count(s[i])) {
      max_seen = std::max(right - left, max_seen);
      while (s[left] != s[i]) {
        char_set.erase(s[left]);
        left++;
      }

      left++;
      right = i;
    }

    char_set.insert(s[right++]);
  }

  max_seen = std::max(right - left, max_seen);

  return max_seen;
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
