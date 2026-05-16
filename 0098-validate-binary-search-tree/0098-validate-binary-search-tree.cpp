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
    bool isValidBST(TreeNode* root, long long low, long long high) {
        if(!root)       return true;

        if(root->val >= high || root->val <= low)
            return false;

        bool leftValid  = isValidBST(root->left, low, root->val);
        bool rightValid = isValidBST(root->right, root->val, high);

        return leftValid && rightValid;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, 1ll*INT_MIN-1, 1ll*INT_MAX+1);
    }
};