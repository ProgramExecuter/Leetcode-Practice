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
    ListNode* removeElements(ListNode* head, int val) {
        // Dummy node before 'head' for ease
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        
        ListNode *curr = dummy;
        
        while(curr -> next) {
            if(curr -> next -> val  ==  val) {
                // Store address of node to be deleted
                ListNode* del = curr -> next;

                // Point to deleted node's next
                curr -> next = curr -> next -> next;

                // Free the deleted node's space in memory
                delete del;
            }
            else {
                // Move ahead
                curr = curr -> next;
            }
        }
        
        // dummy->next contains 'head' of result list
        return dummy->next;
    }
};