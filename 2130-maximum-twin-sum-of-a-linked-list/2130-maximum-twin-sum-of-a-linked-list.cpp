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
    ListNode* reverseList(ListNode* head) {
        if(!head)       return nullptr;
        
        ListNode *curr = head, *prev = nullptr, *nxt = nullptr;
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;

        while(fast) {
            // This works since there are even number of nodes
            fast = fast->next->next;

            prev = slow;
            slow = slow->next;
        }

        // First list =>   head ..... prev
        // Second list =>   end ..... slow
        prev->next = nullptr;
        fast = reverseList(slow);
        slow = head;

        int res = 0;
        while(slow  &&  fast) {
            res = max(res, slow->val + fast->val);
            slow = slow->next;
            fast = fast->next;
        }

        return res;
    }
};