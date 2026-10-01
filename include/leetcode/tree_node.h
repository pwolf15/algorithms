#pragma once

#include <memory>
#include <optional>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

using Level = std::vector<std::optional<int>>;

class TestTree {
  public:
  explicit TestTree(const Level& level) {
    if (level.empty() || !level[0]) return;
    root_ = make(*level[0]);
    std::queue<TreeNode*> q;
    q.push(root_);
    size_t i = 1;
    while (!q.empty()) {
      TreeNode* n = q.front();
      q.pop();
      if (i < level.size() && level[i]) {
        n->left = make(*level[i]);
        q.push(n->left);
      }
      ++i;
      if (i < level.size() && level[i]) {
        n->right = make(*level[i]);
        q.push(n->right);
      }
      ++i;
    }
  }

  TreeNode* root() const { return root_; }

  void print_level_order() {
    if (!root_) return;

    std::queue<TreeNode*> q;
    q.push(root_);

    while (!q.empty()) {
      TreeNode* n = q.front();
      q.pop();
      std::cout << n->val << " ";
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
    std::cout << "\n";
  }

  private:
  TreeNode* make(int v) {
    nodes_.push_back(std::make_unique<TreeNode>(v));
    return nodes_.back().get();
  }
  std::vector<std::unique_ptr<TreeNode>> nodes_;
  TreeNode* root_ = nullptr;
};
