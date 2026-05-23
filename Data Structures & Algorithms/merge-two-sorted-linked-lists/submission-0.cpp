/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* dummy = new ListNode();
      ListNode* curr = dummy;
      ListNode* p1 = list1;
      ListNode* p2 = list2;
      while(p1 != nullptr && p2 != nullptr)
      {
        if(p1->val > p2->val)
        {
            curr->next = p2;
            p2 = p2->next;
            curr = curr->next;
        }
        else
        {
            curr->next = p1;
            p1 = p1->next;
            curr = curr->next;
        }
      }
      while(p1 != nullptr)
      {
        curr->next = p1;
            p1 = p1->next;
            curr = curr->next;
      }
      while(p2 != nullptr)
      {
            curr->next = p2;
            p2 = p2->next;
            curr = curr->next;
      }
      return dummy->next;
    }
};
