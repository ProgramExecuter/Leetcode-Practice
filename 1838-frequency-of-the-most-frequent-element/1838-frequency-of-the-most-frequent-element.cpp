class Solution {
public:
    int maxFrequency(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        
        int st = 0, en = 0, res = 1;
        long long sum = nums[0];
        
        for(int i = 1; i < nums.size(); ++i)
        {
            sum += nums[i];
            en = i;
            
            int len = en-st+1;
            if(sum+k >= 1ll*len*nums[en])
            {
                res = max(res, len);
            }
            else
            {
                sum -= nums[st];
                ++st;
            }
        }
        
        return res;
    }
};