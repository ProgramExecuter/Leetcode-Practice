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
    int n = 0, idxPost = 0;
    
    TreeNode* buildNodes(vector<int>& postorder, vector<int>& inorder, int st, int en) {
        if(st > en || idxPost < 0)      return nullptr;

        TreeNode* root = new TreeNode(postorder[idxPost]);
        int foundIdx = valIdx[postorder[idxPost--]];

        root->right = buildNodes(postorder, inorder, foundIdx+1, en);
        root->left  = buildNodes(postorder, inorder, st, foundIdx-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = postorder.size();
        for(int i = 0; i < n; ++i)
            valIdx[inorder[i]] = i;

        idxPost = n-1;
        return buildNodes(postorder, inorder, 0, n-1);
    }
};