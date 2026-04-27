class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid = 0;

        while(low <= high) {
            mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                return mid;
            } else {
                // Find the sorted side
                // Left is sorted and target lies on left side
                if(nums[low] <= nums[mid]) {
                    if(target >= nums[low] && target < nums[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                // Right is sorted and target lies on right side
                else if(nums[high] >= nums[mid]) {
                    if(target > nums[mid] && target <= nums[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }

        return -1;
    }
};