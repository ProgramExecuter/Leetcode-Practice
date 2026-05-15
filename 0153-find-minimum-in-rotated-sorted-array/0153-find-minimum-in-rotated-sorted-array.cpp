class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1, mid = 0;
        int res = INT_MAX;

        while(low <= high) {
            mid = low + (high - low) / 2;

            // Find the sorted side
            // Left is sorted and target lies on left side
            if(nums[low] <= nums[mid]) {
                res = min(res, nums[low]);
                low = mid + 1;
            }
            // Right is sorted and target lies on right side
            else if(nums[high] >= nums[mid]) {
                res = min(res, nums[mid]);
                high = mid - 1;
            }
        }

        return res;
    }
};