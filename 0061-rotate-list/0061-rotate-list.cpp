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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head || !head->next)
            return head;

        int len = 0;
        ListNode *slow = head, *fast = head;

        while(slow) {
            ++len;
            slow = slow->next;
        }

        k = k % len;
        if(k == 0)      return head;

        while(k > 0) {
            fast = fast->next;
            --k;
        }

        slow = head;
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* tmpHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        head = tmpHead;

        return head;
    }
};