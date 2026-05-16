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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Both on left
        if(p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // Both on right
        else if(p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // One on left and one on right, or one is nth parent of other
        return root;
    }
};