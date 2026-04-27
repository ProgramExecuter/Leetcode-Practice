class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid = 0;

        while(low <= high) {
            mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                return true;
            } else {
                // Find the search space
                if(nums[low] == nums[mid]  &&  nums[mid] == nums[high]) {
                    while(nums[low] == nums[high]) {
                        ++low;  --high;
                        if(low > high) {
                            return false;
                        }
                    }
                }

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

        return false;
    }
};