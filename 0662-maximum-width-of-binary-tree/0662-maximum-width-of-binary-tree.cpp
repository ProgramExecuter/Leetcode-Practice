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
    int widthOfBinaryTree(TreeNode* root) {
        long long res = 0;
        if(!root)       return res;

        // Save node and its assigned index
        queue<pair<TreeNode*, long long>> travQ;
        travQ.push({root, 0});

        while(!travQ.empty()) {
            long long len = travQ.size(), stIdx = travQ.front().second, enIdx = travQ.back().second;
            
            res = max(res, enIdx-stIdx+1);

            while(len--) {
                auto curr = travQ.front();
                travQ.pop();

                int currIdx = curr.second - stIdx;

                if(curr.first->left)        travQ.push({curr.first->left,  2ll*currIdx+1});
                if(curr.first->right)       travQ.push({curr.first->right, 2ll*currIdx+2});
            }
        }

        return res;
    }
};