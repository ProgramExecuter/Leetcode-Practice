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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *first = NULL, *last = NULL, *prevFirst = NULL;
        
        // Dummy node for solving issues relating change of head
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *prev = dummy, *curr = head;
        int idx = 1;
        
        while(curr) {
            ListNode *nxt = curr->next;
            if(idx >= left and idx <= right) {
                curr->next = prev;
                if(idx == left) {
                    prevFirst = prev;
                    first = curr;
                }
                if(idx == right)        last = curr;
            }
            else if(idx > right)      break;
            
            // Move to next and mark previous
            prev = curr;
            curr = nxt;
            ++idx;
        }
        
        // 'curr' becomes next of last node of range
        prevFirst->next = last;
        first->next = curr;
        
        return dummy->next;
    }
};