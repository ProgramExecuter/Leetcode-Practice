class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int j = 0; j < len-3; ++j) {
            if(j > 0  &&  nums[j] == nums[j-1]) { continue; }
            
            for(int i = j+1; i < len-2; ++i) {
                if(i > j+1  &&  nums[i] == nums[i-1]) { continue; }
                
                int st = i+1, en = len-1;
                long long sum = 0;
                while(st < en) {
                    sum = 0ll + nums[j] + nums[i] + nums[st] + nums[en];
                    if(sum == target) {
                        res.push_back({nums[j], nums[i], nums[st], nums[en]});
                        ++st;   --en;
                        while(st < en  &&  nums[st-1] == nums[st]) { ++st; }
                        while(en > st  &&  nums[en] == nums[en+1]) { --en; }
                    } else if(sum < target) {
                        ++st;
                    } else {
                        --en;
                    }
                }
            }
        }

        return res;
    }
};