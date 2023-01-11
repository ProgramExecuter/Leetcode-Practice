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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode(0), *dummyCurr = dummy;
        ListNode *curr = head->next->next, *currNode = head->next;
        
        while(curr) {
            if(curr->val == 0) {
                currNode->next = NULL;
                dummyCurr->next = currNode;
                dummyCurr = dummyCurr->next;
                curr = curr->next;
                currNode = curr;
            }
            else {
                currNode->val += curr->val;
            }
            if(!curr)   break;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};