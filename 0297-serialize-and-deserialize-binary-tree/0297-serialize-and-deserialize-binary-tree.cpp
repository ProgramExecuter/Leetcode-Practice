/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    vector<string> splitString(string str, char splitCh) {
        vector<string> res;
        string curr = "";

        for(char ch : str) {
            if(ch == splitCh) {
                if(curr.size())     res.push_back(curr);
                curr = "";
            } else
                curr += ch;
        }
        if(curr.size())     res.push_back(curr);

        return res;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root)       return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();

            while(len--) {
                TreeNode* curr = q.front();
                q.pop();

                if(!curr) {
                    res += "#,";
                    continue;
                }

                res += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)        return nullptr;
        vector<string> nodes = splitString(data, ',');
        int n = nodes.size();

        int idx = 1;
        TreeNode* root = new TreeNode(stoi(nodes[0]));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty() && idx < n) {
            TreeNode* parent = q.front();
            q.pop();

            if(idx < nodes.size()  &&  nodes[idx] != "#")
                parent->left = new TreeNode(stoi(nodes[idx]));
            ++idx;

            if(idx < nodes.size()  &&  nodes[idx] != "#")
                parent->right = new TreeNode(stoi(nodes[idx]));
            ++idx;

            if(parent->left)    q.push(parent->left);
            if(parent->right)   q.push(parent->right);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));