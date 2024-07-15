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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        set<int> isChildSet;
        map<int, TreeNode*> nodesMap;
        
        for(auto currDescription : descriptions)
        {
            int parent = currDescription[0];
            int child = currDescription[1];
            bool isLeft = currDescription[2];
            
            
            // If nodes not found in map, create new Nodes
            if(nodesMap.find(parent) == nodesMap.end())
                nodesMap[parent] = new TreeNode(parent);
            if(nodesMap.find(child) == nodesMap.end())
                nodesMap[child] = new TreeNode(child);
            
            
            // Add to set of child nodes
            isChildSet.insert(child);
            
            
            // Add child node to right side of parent node
            if(isLeft)
                nodesMap[parent]->left = nodesMap[child];
            else
                nodesMap[parent]->right = nodesMap[child];
        }
        
        // Find the root node
        TreeNode *rootNode = NULL;
        for(auto curr : nodesMap)
        {
            if(isChildSet.find(curr.first) == isChildSet.end())
            {
                rootNode = curr.second;
                break;
            }
        }
        
        return rootNode;
    }
};