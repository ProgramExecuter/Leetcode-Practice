class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        set<int> st;
        int len = nums.size();
        
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] != key)  continue;
            for(int j = max(i-k, 0); j <= min(i+k, len-1); ++j)
                st.insert(j);
        }
        
        vector<int> res;
        for(auto i : st)    res.push_back(i);
        
        return res;
    }
};