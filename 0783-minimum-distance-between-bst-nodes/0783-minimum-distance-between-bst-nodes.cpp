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
    pair<int, int> dfs(TreeNode* root, int &res) {
        if(!root)       return {INT_MIN, INT_MAX};
        
        // Check for minimum and maximum in both child branches
        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        
        int currVal = root->val, leftRes = INT_MAX, rightRes = INT_MAX;
        int currMin = currVal, currMax = currVal;
        
        // If the node exists, then calculate the required variables
        if(left.first != INT_MIN) {
            leftRes = min(leftRes, min(abs(currVal - left.first), abs(currVal - left.second)));
            currMin = min(currMin, left.first);
        }
        if(right.second != INT_MAX) {
            rightRes = min(rightRes, min(abs(currVal - right.first), abs(currVal - right.second)));
            currMax = max(currMax, right.second);
        }
        
        // Find the minimum result
        res = min(res, min(leftRes, rightRes));
        
        // Return the minimum and maximum values of current subtree
        return {currMin, currMax};
    }
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        dfs(root, res);
        
        return res;
    }
};