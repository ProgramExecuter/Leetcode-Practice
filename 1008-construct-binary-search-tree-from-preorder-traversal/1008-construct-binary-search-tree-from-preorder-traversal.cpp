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
    TreeNode* createBST(vector<int>& preorder, int& idx, int& n, int low, int high) {
        if(idx >= n)    return nullptr;

        if(preorder[idx] <= low  ||  preorder[idx] >= high)
            return nullptr;

        TreeNode* newNode = new TreeNode(preorder[idx++]);
        newNode->left  = createBST(preorder, idx, n, low, newNode->val);
        newNode->right = createBST(preorder, idx, n, newNode->val, high);

        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0, n = preorder.size();
        return createBST(preorder, idx, n, INT_MIN, INT_MAX);
    }
};