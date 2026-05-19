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
    TreeNode *first, *last, *mid, *prev;
public:
    void inorder(TreeNode* root) {
        if(!root)   return;

        inorder(root->left);

        if(prev  &&  prev->val >= root->val) {
            // First violation
            if(!first) {
                first = prev;
                mid = root;
            }
            // Second Violation 
            else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)   swap(first->val, last->val);
        else if(first && mid)    swap(first->val, mid->val);
    }
};