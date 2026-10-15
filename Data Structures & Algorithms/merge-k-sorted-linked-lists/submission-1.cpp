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
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
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
            auto top = pq.top();pq.pop();
            curr->next = top;
            curr = curr->next;
            if(top->next)
            {
                pq.push(top->next);
            }
        }
        return dummy->next;
    }
};
