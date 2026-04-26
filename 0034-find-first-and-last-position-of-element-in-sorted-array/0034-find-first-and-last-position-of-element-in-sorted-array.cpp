class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid = 0;
        int firstIdx = n, lastIdx = -1;
        
        // First idx of target
        while(low <= high) {
            mid = low + (high-low)/2;

            if(nums[mid] == target) {
                firstIdx = min(firstIdx, mid);
                high = mid-1;
            } else if(nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        low = 0, high = n-1;

        // Last idx of target
        while(low <= high) {
            mid = low + (high-low)/2;

            if(nums[mid] == target) {
                lastIdx = max(lastIdx, mid);
                low = mid+1;
            } else if(nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        if(firstIdx == n)   firstIdx = -1;

        return {firstIdx, lastIdx};
    }
};