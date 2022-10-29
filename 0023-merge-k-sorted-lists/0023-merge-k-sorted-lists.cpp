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
    // Merge 2 sorted lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Create dummy node, for storing 'head'
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        
        // While any of list is left
        while(l1 || l2) {
            // list1 is exhausted
            if(!l1) {
                prev->next = l2;        break;
            }
            // list2 is exhausted
            if(!l2) {
                prev->next = l1;        break;
            }
            
            if(l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            }
            else {
                prev->next = l2;
                l2 = l2->next;
            }
            
            prev = prev->next;
        }
        
        // Dummy's next contains 'next'
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        
        // Merge each list with previous result
        for(int i = 0; i < lists.size(); ++i)
            result = mergeTwoLists(result, lists[i]);
        
        return result;
    }
};