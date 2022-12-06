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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd{new ListNode(0)}, *even{new ListNode(0)};
        ListNode *curr{head}, *currO{odd}, *currE{even};
        int idx{1};
        
        while(curr) {
            // Save 'next'
            ListNode *nxt = curr->next;                                 

            // Make 'next' of this node = NULL
            curr->next = NULL;
            
            // If the node is even-indexed then push it to even list else push it to odd list
            if(idx%2 == 1) {
                currO->next = curr;
                currO = currO->next;
            }
            else {
                currE->next = curr;
                currE = currE->next;
            }
            
            curr = nxt;
            ++idx;
        }
        
        // Link (odd list) -> (even list)
        currO->next = even->next;
        
        return odd->next;
    }
};