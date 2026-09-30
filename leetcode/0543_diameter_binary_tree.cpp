#include <gtest/gtest.h>

#include "tree_node.h"

namespace p0543 {
int max_height(TreeNode* root) {
  if (root == nullptr)
    return 0;
  else
    return 1 + std::max(max_height(root->left), max_height(root->right));
}

int diameterOfBinaryTree(TreeNode* root) {
  return max_height(root->left) + max_height(root->right);
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
