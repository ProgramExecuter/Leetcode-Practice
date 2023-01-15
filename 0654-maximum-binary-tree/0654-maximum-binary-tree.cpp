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
    TreeNode* f(int st, int en, vector<int> &nums) {
        if(st > en)     return NULL;
        
        // Find the maximum number and that number's index in array
        int idx = st, currMax = nums[st];
        for(int i = st+1; i <= en; ++i)
            if(nums[i] > currMax) {
                currMax = nums[i];
                idx = i;
            }
        
        // Create the new node, and return it
        TreeNode* newNode = new TreeNode(currMax);
        
        newNode->left = f(st, idx-1, nums);
        newNode->right = f(idx+1, en, nums);
        
        return newNode;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return f(0, n-1, nums);
    }
};