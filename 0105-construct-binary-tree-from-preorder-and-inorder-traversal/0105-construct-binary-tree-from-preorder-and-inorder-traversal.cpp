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
    unordered_map<int,int> valIdx;
    int n = 0, idxPre = 0;
    
    TreeNode* buildNodes(vector<int>& preorder, vector<int>& inorder, int st, int en) {
        if(st > en || idxPre >= n)      return nullptr;

        TreeNode* root = new TreeNode(preorder[idxPre]);
        int foundIdx = valIdx[preorder[idxPre++]];

        root->left  = buildNodes(preorder, inorder, st, foundIdx-1);
        root->right = buildNodes(preorder, inorder, foundIdx+1, en);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        for(int i = 0; i < n; ++i)
            valIdx[inorder[i]] = i;

        return buildNodes(preorder, inorder, 0, n-1);
    }
};