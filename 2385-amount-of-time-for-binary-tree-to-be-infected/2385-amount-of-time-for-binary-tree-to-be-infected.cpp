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
    void findParents(TreeNode* root, int& start, map<TreeNode*, TreeNode*>& par, TreeNode*& foundNode) {
        if(!root)   return;

        if(root->val == start) {
            foundNode = root;
        }

        if(root->left) {
            par[root->left] = root;
            findParents(root->left, start, par, foundNode);
        }
        if(root->right) {
            par[root->right] = root;
            findParents(root->right, start, par, foundNode);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* foundNode;

        // Find parents
        map<TreeNode*, TreeNode*> parentMap;
        findParents(root, start, parentMap, foundNode);

        queue<TreeNode*> travQ;
        travQ.push(foundNode);
        int timeTaken = 0;
        set<TreeNode*> visNodes;
        visNodes.insert(foundNode);

        while(!travQ.empty()) {
            int len = travQ.size();

            while(len--) {
                TreeNode* curr = travQ.front();
                travQ.pop();

                // Check Parent
                if(parentMap[curr]  &&  visNodes.count(parentMap[curr]) == 0) {
                    travQ.push(parentMap[curr]);
                    visNodes.insert(parentMap[curr]);
                }

                // Check Left
                if(curr->left  &&  visNodes.count(curr->left) == 0) {
                    travQ.push(curr->left);
                    visNodes.insert(curr->left);
                }

                // Check Right
                if(curr->right  &&  visNodes.count(curr->right) == 0) {
                    travQ.push(curr->right);
                    visNodes.insert(curr->right);
                }
            }

            ++timeTaken;
        }

        return timeTaken-1;
    }
};