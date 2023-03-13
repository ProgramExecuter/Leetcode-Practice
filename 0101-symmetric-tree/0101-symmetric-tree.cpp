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
    bool checkSym(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2)       return true;
        if(!root1 or !root2)        return false;
        
        bool left  = checkSym(root1->left, root2->right);
        bool right = checkSym(root2->left, root1->right);
        
        return root1->val == root2->val  and left and right;
    }
    bool isSymmetric(TreeNode* root) {
        return checkSym(root->left, root->right);
    }
};