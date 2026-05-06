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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)   return res;

        queue<pair<int, TreeNode*>> travQ;
        travQ.push({0, root});

        while(!travQ.empty()) {
            auto frontEle = travQ.front();
            travQ.pop();
            TreeNode* currNode = frontEle.second;
            int level = frontEle.first;

            if(res.size() < level+1) {
                vector<int> tmp;
                res.push_back(tmp);
            }
            res[level].push_back(currNode->val);

            if(currNode->left)      travQ.push({level+1, currNode->left});
            if(currNode->right)     travQ.push({level+1, currNode->right});
        }

        return res;
    }
};