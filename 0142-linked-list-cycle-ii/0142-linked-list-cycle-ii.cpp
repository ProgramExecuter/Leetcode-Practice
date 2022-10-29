/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head  or  !head->next)
            return NULL;
        
        ListNode *fast = head, *slow = head;
        
        while(slow  and  fast  and  fast->next) {       // Use turtle-hare method
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)  break;
        }
        
        if(slow != fast)                                // No Cycle
            return NULL;
        
        slow = head;
        while(slow != fast) {                           // Find intersection point
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};