class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxIdxReachable = 0;
        
        // Find the maximum idx we can reach
        for(int i = 0; i < n-1; ++i) {
            // We cannot reach this index
            if(i > maxIdxReachable)
                return false;
            maxIdxReachable = max(maxIdxReachable, i + nums[i]);
        }
        
        // If the maximum index reached is >= n-1, we can reach last index
        return maxIdxReachable >= n-1;
    }
};