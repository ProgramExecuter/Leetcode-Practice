class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        long long sumStart = 0, sumEnd = 0;
        
        // Store the sum of elements in 'sumEnd' at start
        // then subtract each element to get the sum of last 'n-i-1'
        for(int num : nums)     sumEnd += num;
        
        int resIdx = -1, mnDiff = INT_MAX;
        for(int i = 0; i < n; ++i) {
            // Calculte sum of first 'i+1' elements
            sumStart += nums[i];
            int fromStart = sumStart / (i+1);
            
            // Calculate sum of last 'n-i-1' elements
            sumEnd -= nums[i];
            int fromEnd = (i == n-1) ? 0 : ( sumEnd / (n-i-1) );
            
            int absDiff = abs(fromStart - fromEnd);
            
            // Check is this is new lowest average diff.
            if(absDiff < mnDiff) {
                resIdx = i;
                mnDiff = absDiff;
            }
        }
            
        return resIdx;
    }
};