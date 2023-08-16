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
    pair<ListNode*, int> util(ListNode* head) {
        if(!head)   return {NULL, 0};
        
        auto res = util(head->next);
        int tmp = 2 * head->val + res.second;
        head->val = tmp % 10;
        head->next = res.first;
        
        return {head, tmp / 10};
    }
    ListNode* doubleIt(ListNode* head) {
        pair<ListNode*, int> res = util(head);
        
        if(res.second > 0) {
            ListNode* newHead = new ListNode(res.second);
            newHead->next = res.first;
            return newHead;
        }
        else {
            return res.first;
        }
    }
};