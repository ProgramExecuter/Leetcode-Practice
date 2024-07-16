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
    bool f(TreeNode *currNode, int &val, string &path)
    {
        if(currNode->val == val)
            return true;
        
        if(currNode->left  and  f(currNode->left, val, path))
            path.push_back('L');
        else if(currNode->right  and  f(currNode->right, val, path))
            path.push_back('R');
        
        return !path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue)
    {
        string pathToSource, pathToDest;
        
        f(root, startValue, pathToSource);
        f(root, destValue, pathToDest);
        
        while(!pathToSource.empty() and !pathToDest.empty() and pathToSource.back() == pathToDest.back())
        {
            pathToSource.pop_back();
            pathToDest.pop_back();
        }
        
        string resPath = "";
        for(int i = 0; i < pathToSource.length(); ++i)
            resPath += 'U';

        
        for(int i = pathToDest.size()-1; i >= 0; --i)
           resPath += pathToDest[i];
        
        return resPath;
    }
};