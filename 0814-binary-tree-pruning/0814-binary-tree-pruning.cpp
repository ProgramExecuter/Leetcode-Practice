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
    TreeNode* hasOne(TreeNode* root)
    {
        if(!root)   return NULL;
        
        root->left = hasOne(root->left);
        root->right = hasOne(root->right);
        
        if(root->left  or  root->right  or  root->val == 1)
            return root;
        return NULL;
    }
    TreeNode* pruneTree(TreeNode* root) {
        root = hasOne(root);
        
        return root;
    }
};