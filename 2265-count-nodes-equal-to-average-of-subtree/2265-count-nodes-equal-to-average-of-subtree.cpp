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
class Solution 
{
public:
    pair<int,int> util(TreeNode* root, int &res)
    {
        if(!root)   return {0,0};
        
        auto left = util(root->left, res);
        auto right = util(root->right, res);
        
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        
        if(sum / cnt == root->val)
            ++res;
        
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int res = 0;
        util(root, res);
        
        return res;
    }
};