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
    int heightOfTree(TreeNode* root, bool& isBalanced) {
        if(!root)   return 0;

        int heightLeft = heightOfTree(root->left, isBalanced);
        int heightRight = heightOfTree(root->right, isBalanced);

        if(abs(heightLeft-heightRight) > 1)
            isBalanced = false;

        return 1 + max(heightLeft, heightRight);
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        heightOfTree(root, isBalanced);

        return isBalanced;
    }
};