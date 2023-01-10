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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are NULL, return 'True'
        if(!p  and  !q)         return true;
        
        // If one is NULL and other isn't, return 'False'
        if(!p  or  !q)          return false;
        
        // If the nodes's value aren't same, return 'False'
        if(p->val !=  q->val)   return false;
        
        bool left  = isSameTree(p->left,  q->left);
        bool right = isSameTree(p->right, q->right);
        
        // Check if both left and right subtree are also same
        return (left and right);
    }
};