#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

namespace p0011 {
int maxArea(const std::vector<int>& h) {
  int i = 0, j = static_cast<int>(h.size()) - 1, best = 0;
  while (i < j) {
    best = std::max(best, (j - i) * std::min(h[i], h[j]));
    if (h[i] < h[j]) ++i; else --j;
  }
  return best;
}
}

TEST(P0011, Examples) {
  EXPECT_EQ(p0011::maxArea({1,8,6,2,5,4,8,3,7}), 49);
  EXPECT_EQ(p0011::maxArea({1,1}), 1);
}
TEST(P0011, Edge) {
  EXPECT_EQ(p0011::maxArea({3,8,1,3}), 9);    // keep far-short
  EXPECT_EQ(p0011::maxArea({3,8,1,3,8}), 24); // switch to near-tall
  EXPECT_EQ(p0011::maxArea({}), 0);
}
