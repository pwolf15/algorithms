#include <gmock/gmock.h>

#include <unordered_set>
#include <vector>

namespace p0036 {
bool isValidSudoku(const std::vector<std::vector<char>>& board) {
  bool is_valid = true;

  // check columns
  std::unordered_set<char> vert, horiz;
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (board[i][j] != '.' && vert.count(board[i][j])) return false;
      if (board[j][i] != '.' && horiz.count(board[j][i])) return false;

      vert.insert(board[i][j]);
      horiz.insert(board[j][i]);
    }
    vert.clear();
    horiz.clear();
  }

  std::vector<std::pair<int, int>> grid_corners;
  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      grid_corners.push_back({i, j});
    }
  }
  for (const auto& corner : grid_corners) {
    int x_offset = std::get<0>(corner);
    int y_offset = std::get<1>(corner);
    std::unordered_set<char> grid;
    for (int i = y_offset; i < y_offset + 3; ++i) {
      for (int j = x_offset; j < x_offset + 3; ++j) {
        if (board[i][j] != '.' && grid.count(board[i][j])) return false;

        grid.insert(board[i][j]);
      }
    }
  }

  // check 3x3
  return is_valid;
}
}  // namespace p0036

TEST(P0036, Basic) {
  EXPECT_TRUE(p0036::isValidSudoku({{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}));

  EXPECT_FALSE(p0036::isValidSudoku({{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}));

  EXPECT_FALSE(p0036::isValidSudoku({{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
                                     {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
                                     {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
                                     {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
                                     {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
                                     {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
                                     {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
                                     {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                                     {'.', '.', '4', '.', '.', '.', '.', '.', '.'}}));
};
