class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        // Single element, 0 is avg
        if(n == 1)      return 0;
        
        long long sum = 0;
        vector<long long> front(n, 0), back(n, 0);

        // Calculate the sum of first 'i+1' elements and store the result
        sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            front[i] = sum;
        }
        
        // Calculate the sum of first 'n-i-1' elements and store the result
        sum = 0;
        for(int i = n-1; i >= 0; --i) {
            sum += nums[i];
            back[i] = sum;
        }
        
        int resIdx = -1, mnDiff = INT_MAX;
        for(int i = 0; i < n-1; ++i) {
            // Calculate left and right Average
            int leftAvg  = front[i]  / (i + 1);
            int rightAvg = back[i+1] / (n - i - 1);
            
            int absDiff = abs(leftAvg - rightAvg);
            
            // Check is this is new lowest average diff.
            if(absDiff < mnDiff) {
                resIdx = i;
                mnDiff = absDiff;
            }
        }
        
        // Last Idx
        if(front[n-1] / n  <  mnDiff)
            resIdx = n-1;
            
        return resIdx;
    }
};