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
    int heightOfTree(TreeNode* root, int& res) {
        if(!root)   return 0;

        int leftHeight = heightOfTree(root->left, res);
        int rightHeight = heightOfTree(root->right, res);

        int mxHeight = max(leftHeight, rightHeight);
        res = max(res, leftHeight + rightHeight);

        return 1 + mxHeight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        heightOfTree(root, res);
        return res;
    }
};