class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, cnt = 0;
        vector<int> pre(n, 0);
        map<int, int> mpRem;
        mpRem[0] = 1;
        
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            int rem = sum % k;
            
            if(rem < 0)     rem += k;
            
            cnt += mpRem[rem];
            ++mpRem[rem];
        }
        
        return cnt;
    }
};