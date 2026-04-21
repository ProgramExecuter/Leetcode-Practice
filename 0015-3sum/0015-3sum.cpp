class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < len-2; ++i) {
            if(i > 0  &&  nums[i] == nums[i-1]) { continue; }
            
            int st = i+1, en = len-1, sum = 0;
            while(st < en) {
                sum = nums[i] + nums[st] + nums[en];
                if(sum == 0) {
                    res.push_back({nums[i], nums[st], nums[en]});
                    ++st;   --en;
                    while(st < en  &&  nums[st-1] == nums[st]) { ++st; }
                    while(en > st  &&  nums[en] == nums[en+1]) { --en; }
                } else if(nums[i] + nums[st] + nums[en] < 0) {
                    ++st;
                } else {
                    --en;
                }
            }
        }

        return res;
    }
};