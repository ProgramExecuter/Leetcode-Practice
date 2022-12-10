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
    int findSum(TreeNode* root) {
        if(!root)       return 0;
        
        int l = findSum(root->left);
        int r = findSum(root->right);
        
        return root->val + l + r;
    }
    int util(TreeNode* root, int &sum, int &mnDiff) {
        if(!root)   return 0;
        
        int l = util(root->left , sum, mnDiff);
        int r = util(root->right, sum, mnDiff);
        
        mnDiff = min(mnDiff, abs(2*l - sum));
        mnDiff = min(mnDiff, abs(2*r - sum));
        
        return (l + root->val + r);
    }
    int maxProduct(TreeNode* root) {
        int sum = findSum(root);
        
        int mnDiff = 1e9;
        util(root, sum, mnDiff);
        
        int num1 = (sum - mnDiff) / 2;
        int num2 = num1 + mnDiff;
        
        int mod = 1e9 + 7;
        long long ans = (1ll * num1 * num2 ) % mod;
        
        return int(ans);
    }
};