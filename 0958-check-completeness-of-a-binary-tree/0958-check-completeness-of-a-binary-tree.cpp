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
        queue<TreeNode*> q;
        q.push(root);
        
        bool ended = false, endMarked = false;
        int level = 0;
        
        while(!q.empty()) {
            int len = q.size();
            
            for(int i = 0; i < len; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                
                // Found the end of tree(as it should be)
                if(!curr) {
                    // cout << "N " << q.size() << endl;
                    if(q.size() != 0)   return false;
                    ended = true;
                    break;
                }
                else {
                    // cout << curr->val << " " << q.size() << endl;
                    if(curr->left)          q.push(curr->left);
                    else {
                        if(!endMarked)      q.push(NULL);
                        endMarked = true;
                    }

                    if(curr->right)         q.push(curr->right);
                    else {
                        if(!endMarked)      q.push(NULL);
                        endMarked = true;
                    }
                }
            }
            
            // cout << level << " , " << len << endl;
            
            if((1 << level) != len  and  !ended)
                return false;
            ++level;
        }
        
        return true;
    }
};