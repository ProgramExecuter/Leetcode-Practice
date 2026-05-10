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
    bool checkSymmetry(TreeNode* root1, TreeNode* root2) {
        if(!root1  &&  !root2)      return true;
        if(!root1  ||  !root2)      return false;

        bool leftSym  = checkSymmetry(root1->left, root2->right);
        bool rightSym = checkSymmetry(root1->right, root2->left);

        return  root1->val == root2->val && leftSym && rightSym;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;

        return checkSymmetry(root->left, root->right);
    }
};