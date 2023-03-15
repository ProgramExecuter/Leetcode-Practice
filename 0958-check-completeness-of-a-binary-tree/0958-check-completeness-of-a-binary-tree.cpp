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
    bool isCompleteTree(TreeNode* root) {
        // Queue for level-order traversal
        queue<TreeNode*> q;
        q.push(root);
        
        // Mark if ended the tree, or end is marked via 'NULL'
        bool ended = false, endMarked = false;
        int level = 0;
        
        while(!q.empty()) {
            int len = q.size();
            
            for(int i = 0; i < len; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                
                // Found the end of tree(as it should be)
                if(!curr) {
                    if(q.size() != 0)   return false;
                    ended = true;       break;
                }
                else {
                    // If child node is found, then push it to queue
                    // else, put 'NULL' in queue, and mark it as end
                    if(curr->left)
                        q.push(curr->left);
                    else {
                        if(!endMarked)      q.push(NULL);
                        endMarked = true;
                    }

                    if(curr->right)
                        q.push(curr->right);
                    else {
                        if(!endMarked)      q.push(NULL);
                        endMarked = true;
                    }
                }
            }
            
            if((1 << level) != len  and  !ended)
                return false;
            ++level;
        }
        
        return true;
    }
};