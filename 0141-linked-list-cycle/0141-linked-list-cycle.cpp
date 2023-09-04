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
    bool hasCycle(ListNode *head) {
        if(!head or !head->next)    return false;
        
        ListNode *slow = head, *fast = head;
        
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while(slow != fast  &&  slow  &&  fast  &&  fast->next);
        
        if(slow == fast)    return true;
        return false;
    }
};