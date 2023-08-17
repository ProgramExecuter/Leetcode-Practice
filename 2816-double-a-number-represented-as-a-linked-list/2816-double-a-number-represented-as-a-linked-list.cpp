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
    ListNode* doubleIt(ListNode* head) {
        if(head->val > 4) {
            head = new ListNode(0, head);
        }
        
        for(auto curr = head; curr != NULL; curr = curr->next) {
            curr->val = (curr->val * 2) % 10;
            
            if(curr->next && curr->next->val > 4)
                curr->val += 1;
        }
        
        return head;
    }
};