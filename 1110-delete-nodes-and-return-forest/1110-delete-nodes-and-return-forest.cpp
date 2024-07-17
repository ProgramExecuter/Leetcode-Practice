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
    TreeNode* bfs(TreeNode* root, set<int> &toDelete, vector<TreeNode*> &resRoots, bool isRoot)
    {
        if(!root)   return NULL;

        bool isDeleted = toDelete.find(root->val) != toDelete.end();
        
        if(isRoot and !isDeleted)      resRoots.push_back(root);
        
        root->left = bfs(root->left, toDelete, resRoots, isDeleted);
        root->right = bfs(root->right, toDelete, resRoots, isDeleted);
        
        return isDeleted ? NULL : root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        vector<TreeNode*> resRoots;
        set<int> toDelete;
        
        for(int i : to_delete)
            toDelete.insert(i);
        
        bfs(root, toDelete, resRoots, true);
        
        return resRoots;
    }
};

