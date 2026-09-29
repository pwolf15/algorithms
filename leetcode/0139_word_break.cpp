#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <unordered_set>

namespace p0139 {
bool wordBreak(std::string s, std::vector<std::string> wordDict) {

 if (s.empty()) return true;

 std::cout << "s: " << s << "\n";
 std::unordered_set<std::string> word_set;
 for (const auto& word: wordDict) word_set.insert(word);

 int i = 0;
 while (i <= s.size()) {
  // try break at index i
  std::string a = s.substr(0, i);
  std::string b = s.substr(i, s.size() - i);
  std::cout << "a: " << a << ", b: " << b << " word_count: " << word_set.count(a) << "\n";
  if (word_set.count(a) && wordBreak(b, wordDict)) return true;
  i++; 
 }

 return false;
}
}
TEST(P0139, Basic) {
 EXPECT_EQ(p0139::wordBreak("leetcode", {"leet", "code"}), true);
 EXPECT_EQ(p0139::wordBreak("applepenapple", {"apple", "pen"}), true);
 EXPECT_EQ(p0139::wordBreak("catsandog", {"cats","dog","sand","and","cat"}), false);
}
