/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findLCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res) {
        if(!root)   return false;

        bool left  = findLCA(root->left,  p, q, res);
        bool right = findLCA(root->right, p, q, res);

        if((left && right)  ||  ((left || right) && (root == p || root == q))) {
            res = root;
            return false;
        }
        
        return left || right || root == p || root == q;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = root;
        findLCA(root, p, q, res);
        return res;
    }
};