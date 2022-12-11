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
    int util(TreeNode* root, int &ans) {
        if(!root)       return -1e8;
        
        int l = util(root->left , ans);
        int r = util(root->right, ans);
        
        int tmpAns1 = max(root->val+l+r, max(l, r));
        int tmpAns2 = max(l+root->val, max(root->val, r+root->val));
        
        ans = max(ans, max(tmpAns1, tmpAns2));
        
        return tmpAns2;
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e8;
        
        util(root, ans);
        
        return ans;
    }
};