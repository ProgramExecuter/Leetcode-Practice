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
    void f(TreeNode* root, int &curr, int &sum) {
        // Add this digit to current number
        curr = curr*10 + root->val;
        
        // This is leaf node, add the current number to 'sum'
        if(!root->left  and  !root->right)
            sum += curr;
        
        // Check for left and right sub-tree
        if(root->left)
            f(root->left, curr, sum);
        if(root->right)
            f(root->right, curr, sum);
        
        // Backtrack
        curr /= 10;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0, curr = 0;
        
        f(root, curr, sum);
        
        return sum;
    }
};