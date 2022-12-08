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
    void generateLeafSeq(TreeNode* root, vector<int> &leafSeq) {
        if(!root)   return;
        
        // INORDER TRAVERSAL iterative
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            
            // Pushing leaf node's value to result vector
            if(!curr->left  and  !curr->right) {
                leafSeq.push_back(curr->val);
            }
            else {
                if(curr->left)      st.push(curr->left);
                if(curr->right)     st.push(curr->right);
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSeq1, leafSeq2;
        
        // Generate Leaf Sequences for both trees
        generateLeafSeq(root1, leafSeq1);
        generateLeafSeq(root2, leafSeq2);
        
        int len1 = leafSeq1.size(), len2 = leafSeq2.size();
        
        // IF the lengths differ, then the sequences aren't same
        if(len1 != len2)    return false;
        
        // Check if sequence of both matches
        for(int i = 0; i < len1; ++i) {
            if(leafSeq1[i] != leafSeq2[i])  return false;
        }
        
        return true;
    }
};