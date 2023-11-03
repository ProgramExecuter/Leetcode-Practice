class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        vector<string> res;
        
        for(int curr = 1, idx = 0; curr <= n and idx < len; ++curr)
        {
            // If required, we push to stack
            if(curr == target[idx])
            {
                res.push_back("Push");
                ++idx;
            }
            // If not required, then we put it into stack, and pop it out
            else
            {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        
        return res;
    }
};