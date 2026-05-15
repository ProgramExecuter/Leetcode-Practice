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
    void flatten(TreeNode* root) {
        if(!root)       return;
        stack<TreeNode*> travSt;
        travSt.push(root);

        TreeNode* prev = nullptr;

        while(!travSt.empty()) {
            TreeNode* curr = travSt.top();
            travSt.pop();

            if(curr->right)     travSt.push(curr->right);
            if(curr->left)      travSt.push(curr->left);

            curr->left = curr->right = nullptr;
            if(prev)    prev->right = curr;
            prev = curr;
        }
    }
};