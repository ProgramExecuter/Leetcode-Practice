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
    // util(root, minimumOfAncestor, maximumOfAncestor)
    int util(TreeNode* root, int mn, int mx) {
        if(!root)   return 0;
        
        int currAns = max( abs(mx - root->val) , abs(mn - root->val) );
        
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        
        int leftAns  = util(root->left , mn, mx);
        int rightAns = util(root->right, mn, mx);
        
        return max(currAns, max(leftAns, rightAns));
    }
    int maxAncestorDiff(TreeNode* root) {
        // Using the util() for some extra fields
        return util(root, root->val, root->val);
    }
};