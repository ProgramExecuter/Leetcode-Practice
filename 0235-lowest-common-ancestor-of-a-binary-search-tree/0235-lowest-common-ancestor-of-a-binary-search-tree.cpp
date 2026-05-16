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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q, int low, int high) {
        if(!root)   return root;

        if(root == p || root == q) {
            return root;
        } else {
            // Both on left
            if(p->val < root->val && q->val < root->val) {
                return lca(root->left, p, q, low, root->val);
            }
            // Both on right
            else if(p->val > root->val && q->val > root->val) {
                return lca(root->right, p, q, root->val, high);
            }
            // One on left and one on right
            else {
                return root;
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q, INT_MIN, INT_MAX);
    }
};