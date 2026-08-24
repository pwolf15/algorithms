#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>

using namespace std;

size_t get_bits(const std::vector<std::vector<int>>& rows, int row) {
  size_t bits = 0x0;
  for (const auto& r: rows) {
    if (r[0] == row)
      bits |= 1 << (10 - r[1]);
  }
  return bits;
}

int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> occ;
    for (auto& s : reservedSeats)
        occ[s[0]] |= 1 << (s[1] - 1);

    const int L = 0b0000011110, M = 0b0001111000, R = 0b0111100000; // seats 2-5,4-7,6-9
    int total = 2 * (n - (int)occ.size());
    for (auto& [row, bits] : occ) {
        if (!(bits & (L | R)))            total += 2;   // full 8 ≡ L∧R free
        else if (!(bits & L) || !(bits & M) || !(bits & R)) total += 1;
    }
    return total;
}

int main() {
  std::vector<std::vector<int>> families = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}}; 
  std::cout << maxNumberOfFamilies(3, families) << "\n";
  families = {{2,1},{1,8},{2,6}};
  std::cout << maxNumberOfFamilies(2, families) << "\n";
  families = {{4,3},{1,4},{4,6},{1,7}};
  std::cout << maxNumberOfFamilies(4, families) << "\n";
}
