class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1, mid = 0;
        int res = INT_MAX;

        while(low <= high) {
            mid = low + (high - low) / 2;

            res = min(res, nums[mid]);

            // Find the search space
            if(nums[low] == nums[mid]  &&  nums[mid] == nums[high]) {
                while(nums[low] == nums[high]) {
                    ++low;  --high;
                    if(low > high) {
                        return res;
                    }
                }
            }

            // Find the sorted side
            // Left is sorted and target lies on left side
            if(nums[low] <= nums[mid]) {
                res = min(res, nums[low]);
                low = mid + 1;
            }
            // Right is sorted and target lies on right side
            else if(nums[high] >= nums[mid]) {
                high = mid - 1;
            }
        }

        return false;
    }
};