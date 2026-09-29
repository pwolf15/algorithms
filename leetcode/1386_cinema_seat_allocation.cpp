#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

namespace p1386 {
int maxNumberOfFamilies(int n, const std::vector<std::vector<int>>& reservedSeats) {
  std::unordered_map<int, int> occ;
  for (auto& s : reservedSeats) occ[s[0]] |= 1 << (s[1] - 1);

  const int L = 0b0000011110;  // seats 2-5
  const int M = 0b0001111000;  // seats 4-7
  const int R = 0b0111100000;  // seats 6-9

  int total = 2 * (n - (int)occ.size());
  for (auto& [row, bits] : occ) {
    if (!(bits & (L | R)))
      total += 2;
    else if (!(bits & L) || !(bits & M) || !(bits & R))
      total += 1;
  }
  return total;
}
}  // namespace p1386

TEST(P1386, Basic) {
  EXPECT_EQ(p1386::maxNumberOfFamilies(3, {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}}), 4);
  EXPECT_EQ(p1386::maxNumberOfFamilies(2, {{2, 1}, {1, 8}, {2, 6}}), 2);
  EXPECT_EQ(p1386::maxNumberOfFamilies(4, {{4, 3}, {1, 4}, {4, 6}, {1, 7}}), 4);
}
