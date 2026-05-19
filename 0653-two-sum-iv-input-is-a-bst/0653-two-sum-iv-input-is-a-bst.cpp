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
class BSTIterator {
    stack<TreeNode*> nextSt, beforeSt;

public:
    BSTIterator(TreeNode* root) {
        TreeNode* tmp = root;

        // Push all left to nextSt stack
        while(tmp) {
            nextSt.push(tmp);
            tmp = tmp->left;
        }

        tmp = root;
        // Push all right to beforeSt stack
        while(tmp) {
            beforeSt.push(tmp);
            tmp = tmp->right;
        }
    }
    
    int next() {
        TreeNode* curr = nextSt.top();
        nextSt.pop();

        int res = curr->val;
        curr = curr->right;

        while(curr) {
            nextSt.push(curr);
            curr = curr->left;
        }

        return res;
    }

    int before() {
        TreeNode* curr = beforeSt.top();
        beforeSt.pop();

        int res = curr->val;
        curr = curr->left;

        while(curr) {
            beforeSt.push(curr);
            curr = curr->right;
        }

        return res;
    }

    int hasBefore() {
        return !beforeSt.empty();
    }
    
    bool hasNext() {
        return !nextSt.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator obj(root);
        int st = obj.next(), en = obj.before();

        while(obj.hasBefore()  &&  obj.hasNext()) {
            if(st == en)
                return false;
            
            int sum = st + en;

            if(sum == k)
                return true;
            else if(sum > k)
                en = obj.before();
            else
                st = obj.next();
        }

        return false;
    }
};