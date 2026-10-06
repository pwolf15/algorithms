#include <gmock/gmock.h>

#include <string>
#include <vector>

namespace p0271 {
std::string encode(const std::vector<std::string>& strs) {
  std::string str_enc;
  for (const auto& str : strs) {
    str_enc += std::to_string(str.size());
    str_enc += "#";
    str_enc += str;
  }
  return str_enc;
}
std::vector<std::string> decode(std::string s) {
  std::vector<std::string> out;
  size_t offset = 0;
  while (offset < s.size()) {
    size_t hash = s.find('#', offset);
    int len = std::stoi(s.substr(offset, hash - offset));
    out.push_back(s.substr(hash + 1, len));
    offset = hash + 1 + len;
  }
  return out;
}
}  // namespace p0271

#include <iostream>

TEST(P0271, Basic) {
  EXPECT_EQ(p0271::decode(p0271::encode({"Hello", "World"})),
            std::vector<std::string>({"Hello", "World"}));
  EXPECT_EQ(p0271::decode(p0271::encode({""})), std::vector<std::string>({""}));
  EXPECT_EQ(p0271::decode(p0271::encode({"", "vn"})), std::vector<std::string>({"", "vn"}));
}
