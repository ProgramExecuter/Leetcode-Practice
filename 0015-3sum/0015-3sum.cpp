class Solution {
public:
    void twoSum(vector<int>& nums, int st, int en, vector<vector<int>>& res, int target) {
        while(st < en) {
            if(nums[st] + nums[en] == target) {
                res.push_back({-1*target, nums[st], nums[en]});
                ++st;   --en;
                while(st < en  &&  nums[st-1] == nums[st]) { ++st; }
                while(en > st  &&  nums[en] == nums[en+1]) { --en; }
            } else if(nums[st] + nums[en] < target) {
                ++st;
            } else {
                --en;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < len; ++i) {
            if(i > 0  &&  nums[i] == nums[i-1]) { continue; }
            twoSum(nums, i+1, len-1, res, 0-nums[i]);
        }

        return res;
    }
};