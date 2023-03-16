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
    TreeNode* solve(vector<int>& in, vector<int>& post, int &postIdx, int low, int high, map<int, int> &mp) {
        if(low > high  or  postIdx < 0)
            return NULL;
        
        TreeNode* curr = new TreeNode(post[postIdx]);
        int idxI = mp[post[postIdx]];
        
        --postIdx;
        
        curr->right = solve(in, post, postIdx, idxI+1, high  , mp);
        curr->left  = solve(in, post, postIdx, low   , idxI-1, mp);
        
        return curr;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        map<int, int> mp;
        for(int i = 0; i < in.size(); ++i)
            mp[in[i]] = i;
        
        int postIdx = post.size()-1;
        return solve(in, post, postIdx, 0, in.size()-1, mp);
    }
};