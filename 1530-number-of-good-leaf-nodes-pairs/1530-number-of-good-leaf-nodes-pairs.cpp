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
    vector<int> dfs(TreeNode* root, int &distance, int &res)
    {
        vector<int> distanceNodes(distance + 1);
        
        if(!root)
            return distanceNodes;
        
        if(!root->left  and  !root->right)
        {
            // Distance of leaf node to nearest parent node = 1
            distanceNodes[1] = 1;
            return distanceNodes;
        }
        
        vector<int> left = dfs(root->left, distance, res);
        vector<int> right = dfs(root->right, distance, res);
        
        // Calculate result
        for(int i = 1; i <= distance; ++i)
        {
            for(int j = 1; j <= distance; ++j)
                if(i + j <= distance)
                    res += left[i] * right[j];
        }
        
        // Increment distance from next parent by 1
        for(int i = distance; i >= 2; --i)
            distanceNodes[i] = left[i-1] + right[i-1];
        
        return distanceNodes;
    }
    int countPairs(TreeNode* root, int distance)
    {
        // vector<int> nodesDist(distance+1);
        
        int res = 0;
        dfs(root, distance, res);
        
        return res;
    }
};