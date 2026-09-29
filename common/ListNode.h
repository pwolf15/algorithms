#pragma once

#include <memory>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct TestList {
  std::vector<std::unique_ptr<ListNode>> nodes;

  TestList(std::initializer_list<int> vals, int cycle_to = -1) {
    for (int v : vals) nodes.push_back(std::make_unique<ListNode>(v));
    for (size_t i = 0; i + 1 < nodes.size(); ++i) nodes[i]->next = nodes.at(i + 1).get();
    if (cycle_to >= 0 && !nodes.empty()) nodes.back()->next = nodes.at(cycle_to).get();
  }

  ListNode* head() const { return nodes.empty() ? nullptr : nodes.front().get(); }
  ListNode* at(size_t i) const { return nodes.at(i).get(); }
};
