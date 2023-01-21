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
    int pairSum(ListNode* head) {
        int idx = 0, len = 0;
        ListNode *slow = head, *fast = head;
        
        // Find the half length of the linked list
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            ++len;
        }
        // Now slow contains head of other half
        
        ListNode *prev = NULL, *nxt = NULL, *curr = slow;
        while(curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        int res = 0;
        
        // Now 'prev' contains last node
        ListNode *front = head, *back = prev;
        while(len--) {
            res = max(res, (front->val + back->val));
            front = front->next;
            back = back->next; 
        }
        
        return res;
    }
};