class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, cnt = 0;
        vector<int> pre(n, 0);
        map<int, int> mpRem;                // To track the count of remainder appearing
        mpRem[0] = 1;                       // To make sure, we get 1st %k = 0
        
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            int rem = sum % k;
            
            if(rem < 0)     rem += k;       // Make remainder +ve, for ease
            
            cnt += mpRem[rem];
            ++mpRem[rem];
        }
        
        return cnt;
    }
};