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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);                  // Take dummy node for ease
        
        ListNode *l1 = list1, *l2 = list2, *curr = dummy;   
        
        while(l1  &&  l2) {
            if(l1->val < l2->val) {                         // Take the node which has lower value
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            
            curr = curr->next;                              // Move to next
        }
        
        curr->next = l1 ? l1 : l2;                          // Append the list which is remaining
        
        return dummy->next;
    }
    ListNode* mergeSort(ListNode* head) {
        if(!head  ||  !head->next)                              // If <= 1 node, return HEAD
            return head;
        
        ListNode *slow = head, *fast = head, *prev = NULL;
        
        while(fast  &&  fast->next) {
            prev = slow;                                        // save previous of 'slow'
            slow = slow->next;                                  // 'fast' moves 2X faster than 'slow'
            fast = fast->next->next;
        }
        
        prev->next = NULL;                                      // Break list into two parts (head, slow)
        
        ListNode *l1, *l2;
        l1 = mergeSort(head);                                   // Save sorted lists of 2 parts in (l1, l2)
        l2 = mergeSort(slow);
        
        head = merge(l1, l2);
        
        return head;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};