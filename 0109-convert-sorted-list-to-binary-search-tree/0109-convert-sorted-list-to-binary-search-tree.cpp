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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)       return NULL;
        ListNode *mid, *slow = head, *fast = head, *prev = NULL;
        
        // Find middle of list
        while(fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow;
        
        // Slow contains 'mid' node of list, and 'prev' contains last node of left list
        // and right list starts from mid->next
        ListNode *list1 = head, *list2 = mid->next;
        
        // If they are same, then there is no left list
        if(list1 == mid)    list1 = NULL;
        
        // Disconnect left list, if it exists
        if(list1)        prev->next = NULL;
        
        // Create the tree node
        TreeNode *newNode = new TreeNode(mid->val);
        newNode->left = sortedListToBST(list1);
        newNode->right = sortedListToBST(list2);
        
        return newNode;
    }
};