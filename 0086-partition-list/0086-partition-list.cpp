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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *newCurr=dummy, *prev=dummy, *curr=head;
        
        while(curr) {
            ListNode *nxt = curr->next;                     // Save next node
            
            
            if(curr->val < x) {
                if(newCurr->next == curr) {
                    prev = newCurr = curr;
                }
                else {
                    prev->next = nxt;                       // Remove curr node from position

                    curr->next = newCurr->next;             // Put 'curr' to right place
                    newCurr->next = curr;

                    newCurr = newCurr->next;                // Move 'newCurr' ahead
                }
            }
            else
                prev = curr;
            
            curr = nxt;                                     // Move ahead
        }
        
        return dummy->next;                                 // Return modified list
    }
};