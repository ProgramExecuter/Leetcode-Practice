class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        int res = nums[0] + nums[len-1];
        
        int i = 1, j = len-2;
        while(i < j)
        {
            int curr = nums[i++] + nums[j--];
            res = max(res, curr);
        }
        
        return res;
    }
};