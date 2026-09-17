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
#define li ListNode*

class compare
{
    public:
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<li,vector<li>,compare>pq;
        for(auto l : lists)
        {
            if(l)
            {
                pq.push(l);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(!pq.empty())
        {
            auto node = pq.top();pq.pop();
            curr ->next = node;
            curr = curr->next;
            if(node->next)
            {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};
