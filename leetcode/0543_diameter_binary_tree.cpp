#include <gtest/gtest.h>

#include "tree_node.h"

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
  TreeNode* t1 = new TreeNode(1);
  t1->left = new TreeNode(2);
  EXPECT_EQ(p0543::diameterOfBinaryTree(t1), 1);

  TreeNode* t2 = new TreeNode(1);
  t2->left = new TreeNode(2);
  t2->right = new TreeNode(3);
  t2->left->left = new TreeNode(4);
  t2->left->right = new TreeNode(5);
  EXPECT_EQ(p0543::diameterOfBinaryTree(t2), 3);

  TreeNode* t3 = new TreeNode(1);
  t3->left = new TreeNode(2);
  t3->left->left = new TreeNode(3);
  t3->left->left->left = new TreeNode(5);
  t3->left->right = new TreeNode(4);
  t3->left->right->right = new TreeNode(6);
  EXPECT_EQ(p0543::diameterOfBinaryTree(t3), 4);
}
