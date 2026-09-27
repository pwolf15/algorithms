#pragma once

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

struct TestList {
  std::vector<std::unique_ptr<ListNode>> nodes;

  TestList(std::initializer_list<int> vals, int cycle_to = -1) {
    for (int v: vals) nodes.push_back(std::make_unique<ListNode>(v));
    for (size_t i = 0; i + 1 <nodes.size(); ++i) nodes[i]->next = nodes[i + 1].get();
    if (cycle_to >= 0 && !nodes.empty()) nodes.back()->next = nodes[cycle_to].get();
  }

  ListNode* head() const { return nodes.empty() ? nullptr: nodes.front().get(); }
  ListNode* at(size_t i) const { return nodes[i].get(); }
};
