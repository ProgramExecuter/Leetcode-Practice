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
    vector<int> largestValues(TreeNode* root) {
        vector<TreeNode*> curr;
        vector<int> res;
        
        // Push first root node for Level-Order Traversal
        if(root)    curr.push_back(root);
        
        while(curr.size() > 0)
        {
            vector<TreeNode*> next;
            int mx = INT_MIN;
            
            for(int i = 0; i < curr.size(); ++i)
            {
                TreeNode* currNode = curr[i];
                mx = max(mx, currNode->val);
                
                if(currNode->left)  next.push_back(currNode->left);
                if(currNode->right) next.push_back(currNode->right);
            }
            
            res.push_back(mx);
            curr = next;
        }
        
        return res;
    }
};