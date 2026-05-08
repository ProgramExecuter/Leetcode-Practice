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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((!p && q)  ||  (!q && p))
            return false;
        if(!p && !q)
            return true;
        
        bool checkLeft  = isSameTree(p->left,  q->left);
        bool checkRight = isSameTree(p->right, q->right);

        return checkLeft & checkRight && p->val == q->val;
    }
};