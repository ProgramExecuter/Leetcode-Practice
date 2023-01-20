class Solution {
public:
    void f(int idx, int prev, vector<int> &nums, vector<int> &curr, set<vector<int>> &res) {
        if(idx == nums.size()) {
            if(curr.size() > 1)     res.insert(curr);
            return;
        }
        
        // Pick
        if(nums[idx] >= prev) {
            curr.push_back(nums[idx]);
            f(idx+1, nums[idx], nums, curr, res);
            curr.pop_back();
        }
        
        // Not Pick
        f(idx+1, prev, nums, curr, res);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // Set used for ignoring duplicates
        set<vector<int>> res;
        vector<int> curr;
        
        f(0, INT_MIN, nums, curr, res);
        
        vector<vector<int>> ans;
        for(auto i : res)
            ans.push_back(i);
        
        return ans;
    }
};