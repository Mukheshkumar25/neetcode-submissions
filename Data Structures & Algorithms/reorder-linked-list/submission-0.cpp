class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* part1 = head;
        ListNode* part2 = slow->next;

        slow->next = nullptr;

        // Reverse part2
        ListNode* prev = nullptr;
        ListNode* curr = part2;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        part2 = prev;

        // Merge part1 and part2
        ListNode* dummy = new ListNode();
        curr = dummy;

        while (part1 && part2) {

            ListNode* next1 = part1->next;
            ListNode* next2 = part2->next;

            curr->next = part1;
            curr = curr->next;

            curr->next = part2;
            curr = curr->next;

            part1 = next1;
            part2 = next2;
        }

        while (part1) {
            curr->next = part1;
            curr = curr->next;
            part1 = part1->next;
        }

        while (part2) {
            curr->next = part2;
            curr = curr->next;
            part2 = part2->next;
        }
    }
};