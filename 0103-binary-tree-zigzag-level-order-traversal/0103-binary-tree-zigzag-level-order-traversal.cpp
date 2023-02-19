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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Use queue for level-order traversal
        queue<TreeNode*> q;
        if(root)    q.push(root);
        
        vector<vector<int>> res;
        int level = 0;          // Represents level of tree
        
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            
            for(int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                
                if(curr->left)      q.push(curr->left);
                if(curr->right)     q.push(curr->right);
            }
            
            // Every 2nd level is reversed for zig-zag traversal
            if(level % 2)   reverse(tmp.begin(), tmp.end());
            
            res.push_back(tmp);
            ++level;
        }
        
        return res;
    }
};