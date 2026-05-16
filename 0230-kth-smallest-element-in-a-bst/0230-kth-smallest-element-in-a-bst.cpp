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
    struct ChildCnt {
        int leftCnt;
        int rightCnt;

        ChildCnt(int left = 0, int right = 0)
            : leftCnt(left), rightCnt(right) {}
    };

    int findChildCnt(TreeNode* root, map<TreeNode*, ChildCnt>& mp) {
        if(!root)       return 0;

        int left  = findChildCnt(root->left,  mp);
        int right = findChildCnt(root->right, mp);

        mp[root] = ChildCnt(left, right);

        return 1 + left + right;
    }
    int kthSmallest(TreeNode* root, int k) {
        // Find left and right node cnt for each node
        map<TreeNode*, ChildCnt> mpChildCnt;
        findChildCnt(root, mpChildCnt);

        int numsSmallerThanCurr = 0;
        TreeNode* curr = root;
        while(curr) {
            int tmpSmallCnt = numsSmallerThanCurr + mpChildCnt[curr].leftCnt;
            // Found the element
            if(tmpSmallCnt == k-1) {
                return curr->val;
            } else if(tmpSmallCnt >= k) {
                curr = curr->left;
            } else {
                numsSmallerThanCurr = tmpSmallCnt + 1;
                curr = curr->right;
            }
        }

        return -1;
    }
};