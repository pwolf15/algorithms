#include <cstddef>

#include <gtest/gtest.h>
#include <ListNode.h>

namespace p0141 {
bool hasCycle(ListNode* head) {
#ifdef BRUTE_FORCE

#else

  // 2 pointers approach
  ListNode *p_step1, *p_step2;

  // stopping condition: compare with head
  p_step1 = p_step2 = head;
 
  while (true) {
    if (!p_step1 || !p_step2) return false;
   
    // advance 1 step 
    p_step1 = p_step1->next;
    
    // advance 2 steps
    p_step2 = p_step2->next;

    if (!p_step2) return false;
    p_step2 = p_step2->next;

    if (p_step1 == p_step2 && p_step1) return true;
  }

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
