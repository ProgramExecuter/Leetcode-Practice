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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // value to  { node, parentNode }
        map<int, pair<TreeNode*, TreeNode*>> valToNodeAndPar;

        for(auto rel : descriptions) {
            TreeNode *currPar, *currChild;

            if(valToNodeAndPar.count(rel[0]) == 0) {
                currPar = new TreeNode(rel[0]);
                valToNodeAndPar[rel[0]] = {currPar, nullptr};
            }
            else
                currPar = valToNodeAndPar[rel[0]].first;
            
            if(valToNodeAndPar.count(rel[1]) == 0) {
                currChild = new TreeNode(rel[1]);
                valToNodeAndPar[rel[1]] = {currChild, currPar};
            }
            else {
                currChild = valToNodeAndPar[rel[1]].first;
                valToNodeAndPar[rel[1]].second = currPar;
            }
            
            if(rel[2])      currPar->left  = currChild;
            else            currPar->right = currChild;
        }

        for(auto childPar : valToNodeAndPar) {
            if(childPar.second.second == nullptr)
                return childPar.second.first;
        }

        return nullptr;
    }
};