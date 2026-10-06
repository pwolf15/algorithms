#include <gmock/gmock.h>

#include <string>
#include <vector>

namespace p0271 {
struct Header {
  int num_words;
  std::vector<int> sizes;
};
std::string pad(int n, int width) {
  std::string result;
  while (n) {
    result = std::to_string(n % 10) + result;
    n /= 10;
  }
  while (result.size() < width) {
    result = "0" + result;
  }
  return result;
}

std::string encode(const std::vector<std::string>& strs) {
  Header header;
  header.num_words = strs.size();
  for (const auto& str : strs) {
    header.sizes.push_back(str.size());
  }
  std::string str_enc = pad(header.num_words, 3);
  for (int size : header.sizes) {
    str_enc += pad(size, 4);
  }
  for (const auto& str : strs) {
    str_enc += str;
  }
  return str_enc;
}
std::vector<std::string> decode(std::string s) {
  Header header;
  header.num_words = std::atoi(s.substr(0, 3).c_str());
  int num_words = header.num_words;
  int offset = 3;
  while (num_words) {
    header.sizes.push_back(std::atoi(s.substr(offset, 4).c_str()));
    offset += 4;
    num_words--;
  }
  num_words = header.num_words;
  std::vector<std::string> vec_dec;
  int i = 0;
  while (num_words) {
    vec_dec.push_back(s.substr(offset, header.sizes[i]));
    offset += header.sizes[i];
    num_words--;
  }
  return vec_dec;
}
}  // namespace p0271

#include <iostream>

TEST(P0271, Basic) {
  EXPECT_EQ(p0271::encode({"Hello", "World"}), "00200050005HelloWorld");
  EXPECT_EQ(p0271::decode("00200050005HelloWorld"), std::vector<std::string>({"Hello", "World"}));
  EXPECT_EQ(p0271::decode(p0271::encode({"Hello", "World"})),
            std::vector<std::string>({"Hello", "World"}));
  EXPECT_EQ(p0271::decode(p0271::encode({""})), std::vector<std::string>({""}));
}
