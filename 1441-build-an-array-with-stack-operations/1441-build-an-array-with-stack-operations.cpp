class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        vector<string> res;
        
        for(int curr = 1, idx = 0; curr <= n and idx < len; ++curr)
        {
            if(curr == target[idx])
            {
                res.push_back("Push");
                ++idx;
            }
            else
            {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        
        return res;
    }
};