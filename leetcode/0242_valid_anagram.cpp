#include <gmock/gmock.h>

namespace p0242 {
bool isAnagram(std::string s, std::string t) {
  if (s.size() != t.size()) return false;

  std::array<int, 26> char_count;
  char_count.fill(0);
  for (char c : s) {
    char_count[c - 'a']++;
  }
  for (char c : t) {
    char_count[c - 'a']--;
  }

  for (int count : char_count) {
    if (count > 0) return false;
  }

  return true;
}
}  // namespace p0242

TEST(P0242, Basic) {
  EXPECT_TRUE(p0242::isAnagram("anagram", "nagaram"));
  EXPECT_FALSE(p0242::isAnagram("rat", "car"));
}
