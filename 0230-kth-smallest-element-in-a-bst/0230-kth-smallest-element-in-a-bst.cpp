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
    void dfs(TreeNode* root, vector<int>& sortedArr) {
        if(!root)   return;

        dfs(root->left, sortedArr);
        sortedArr.push_back(root->val);
        dfs(root->right, sortedArr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sortedArr;
        dfs(root, sortedArr);
        return sortedArr[k-1];
    }
};