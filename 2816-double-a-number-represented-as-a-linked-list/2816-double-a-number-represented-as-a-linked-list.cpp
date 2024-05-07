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
class Solution
{
public:
    pair<ListNode*,int> f(ListNode* head)
    {
        if(!head)       return {NULL, 0};
        
        auto tmp = f(head->next);
        
        int num = head->val * 2 + tmp.second;
        int tmpRem = num / 10;
        num = num % 10;
        
        head->val = num;
        return {head, tmpRem};
    }
    ListNode* doubleIt(ListNode* head)
    {
        pair<ListNode*, int> res = f(head);
        ListNode* newHead = NULL;
        
        if(res.second != 0)
        {
            newHead = new ListNode(res.second);
            newHead->next = res.first;
        }
        else
        {
            newHead = res.first;
        }
        
        return newHead;
    }
};