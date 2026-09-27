#include <gtest/gtest.h>
#include <ListNode.h>

namespace p0876 {
ListNode* middleNode(ListNode* head) {
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
 
  return slow;
}
}

TEST(P0876, Basic) {

  ListNode* l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(3);
  l1->next->next->next = new ListNode(4);
  l1->next->next->next->next = new ListNode(5);

  EXPECT_EQ(p0876::middleNode(l1), l1->next->next); 

  ListNode* l2 = new ListNode(1);
  l2->next = new ListNode(2);
  l2->next->next = new ListNode(3);
  l2->next->next->next = new ListNode(4);
  l2->next->next->next->next = new ListNode(5);
  l2->next->next->next->next->next = new ListNode(6);

  EXPECT_EQ(p0876::middleNode(l2), l2->next->next->next);
}
