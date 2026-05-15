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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *dummy = new TreeNode(0);
        dummy->left = root;
        dummy->right = nullptr;

        TreeNode *curr = root, *par = dummy;
        bool isLeft = true;

        while(curr) {
            if(curr->val == key) {
                if(!curr->left && !curr->right) {
                    if(isLeft)  par->left = nullptr;
                    else        par->right = nullptr;
                } else if(!curr->left) {
                    if(isLeft)  par->left = curr->right;
                    else        par->right = curr->right;
                } else if(!curr->right) {
                    if(isLeft)  par->left = curr->left;
                    else        par->right = curr->left;
                } else {
                    TreeNode* tmp = curr->left;
                    while(tmp->right)
                        tmp = tmp->right;

                    tmp->right = curr->right;

                    if(isLeft)  par->left = curr->left;
                    else        par->right = curr->left;
                }

                return dummy->left;
            } else if(curr->val > key) {
                par = curr;
                isLeft = true;
                curr = curr->left;
            } else {
                par = curr;
                isLeft = false;
                curr = curr->right;
            }
        }

        return dummy->left;
    }
};