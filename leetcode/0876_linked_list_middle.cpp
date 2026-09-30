#include <list_node.h>
#include <gtest/gtest.h>

namespace p0876 {
ListNode* middleNode(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}
}  // namespace p0876

TEST(P0876, OddLength) {
  TestList l{1, 2, 3, 4, 5};
  EXPECT_EQ(p0876::middleNode(l.head()), l.at(2));
}

TEST(P0876, EvenLength) {
  TestList l{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(p0876::middleNode(l.head()), l.at(3));
}
