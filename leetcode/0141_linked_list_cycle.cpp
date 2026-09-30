#include <gtest/gtest.h>
#include <list_node.h>

#include <cstddef>

// brute force solution
#include <iostream>
#include <unordered_set>

namespace p0141 {
bool hasCycle(ListNode* head) {
#ifdef BRUTE_FORCE
  std::unordered_set<ListNode*> nodes_seen;

  while (head) {
    if (nodes_seen.find(head) != nodes_seen.end()) return true;

    nodes_seen.insert(head);

    head = head->next;
  }

  return false;
#else

  // 2 pointers approach
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }

  return false;
#endif
}
}  // namespace p0141

TEST(P0141, Cycle) {
  EXPECT_TRUE(p0141::hasCycle(TestList({1, 2, 3, 4, 5}, 2).head()));
  EXPECT_FALSE(p0141::hasCycle(TestList({1, 2, 3}).head()));
  EXPECT_FALSE(p0141::hasCycle(TestList({}).head()));
}
