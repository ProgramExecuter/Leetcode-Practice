/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> travQ;
        travQ.push(root);

        map<TreeNode*, TreeNode*> nodePar;
        nodePar[root] = NULL;

        while(!travQ.empty()) {
            int len = travQ.size();

            while(len--) {
                TreeNode* curr = travQ.front();
                travQ.pop();

                if(curr->left) {
                    travQ.push(curr->left);
                    nodePar[curr->left] = curr;
                }
                if(curr->right) {
                    travQ.push(curr->right);
                    nodePar[curr->right] = curr;
                }
            }
        }

        vector<int> res;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        set<TreeNode*> visNodes;
        visNodes.insert(target);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            if(curr.second == k) {
                res.push_back(curr.first->val);
                continue;
            }

            if(nodePar[curr.first]  &&  visNodes.count(nodePar[curr.first]) == 0) {
                q.push({nodePar[curr.first], curr.second+1});
                visNodes.insert(nodePar[curr.first]);
            }
            if(curr.first->left  &&  visNodes.count(curr.first->left) == 0) {
                nodePar[curr.first->left] = curr.first;
                visNodes.insert(curr.first->left);
                q.push({curr.first->left, curr.second+1});
            }
            if(curr.first->right  &&  visNodes.count(curr.first->right) == 0) {
                nodePar[curr.first->right] = curr.first;
                visNodes.insert(curr.first->right);
                q.push({curr.first->right, curr.second+1});
            }
        }

        return res;
    }
};