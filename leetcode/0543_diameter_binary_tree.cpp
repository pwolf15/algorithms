#include <gtest/gtest.h>

#include "tree_node.h"

constexpr auto _ = std::nullopt;

namespace p0543 {
struct Info {
  int height;
  int diameter;
};

Info walk(TreeNode* root) {
  if (root == nullptr) return {0, 0};
  Info l = walk(root->left);
  Info r = walk(root->right);
  return {1 + std::max(l.height, r.height),
          std::max({l.diameter, r.diameter, l.height + r.height})};
}

int diameterOfBinaryTree(TreeNode* root) {
  return walk(root).diameter;
}
}  // namespace p0543

TEST(P0543, Basic) {
  TestTree t1({1, 2, _});
  EXPECT_EQ(p0543::diameterOfBinaryTree(t1.root()), 1);

  TestTree t2({1, 2, 3, 4, 5});
  EXPECT_EQ(p0543::diameterOfBinaryTree(t2.root()), 3);

  // longest path avoids the root
  TestTree t3({1, 2, _, 3, 4, 5, _, 6, _});
  EXPECT_EQ(p0543::diameterOfBinaryTree(t3.root()), 4);
}
