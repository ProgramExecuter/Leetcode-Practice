class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int res = INT_MAX;
        set<int> st;
        
        for(int i = x; i < nums.size(); ++i) {
            st.insert(nums[i-x]);
            auto itr = st.upper_bound(nums[i]);
            
            if(itr != st.end())     res = min(res, abs(nums[i] - *itr));
            if(itr != st.begin())   res = min(res, abs(nums[i] - *prev(itr)));
        }
        
        return res;
    }
};