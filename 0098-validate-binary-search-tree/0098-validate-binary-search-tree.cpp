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
    bool isValidBST(TreeNode* root, long long low = INT_MIN, long long high = INT_MAX) {
        if(!root)       return true;

        if(root->val > high || root->val < low)
            return false;

        bool leftValid  = isValidBST(root->left, low, 1ll*root->val-1);
        bool rightValid = isValidBST(root->right, 1ll*root->val+1, high);

        return leftValid && rightValid;
    }
};