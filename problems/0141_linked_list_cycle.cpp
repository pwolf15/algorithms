#include <cstddef>

#include <gtest/gtest.h>
#include <ListNode.h>

// brute force solution
#include <unordered_set>
#include <iostream>

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
  ListNode *slow = head;
  ListNode *fast = head;
 
  while (fast && fast->next) {

    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }

  return false;
#endif
}
}

TEST(P0141, Basic) {
  
  // example 1
  ListNode* l1 = new ListNode(3);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(0);
  l1->next->next->next = new ListNode(-4);
  l1->next->next->next->next = l1->next;

  EXPECT_EQ(p0141::hasCycle(l1->next), true);

  // example 2
  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(2);
  l2->next->next = l2;

  EXPECT_EQ(p0141::hasCycle(l2), true);

  // example 3
  ListNode *l3 = new ListNode(1);
  
  EXPECT_EQ(p0141::hasCycle(l3), false);
}
