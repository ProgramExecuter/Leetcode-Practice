class Solution {
public:
    int checkIncrDecrOrThis(vector<int>& nums, int& mid, int& n) {
        if(mid-1 >= 0) {
            if(mid+1 < n) {
                if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                    return 0;
                else if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1])
                    return 1;
                else
                    return 2;
            } else {
                if(nums[mid-1] < nums[mid])
                    return 0;
                else
                    return 2;
            }
        } else {
            if(mid+1 < n) {
                if(nums[mid] < nums[mid+1])
                    return 1;
                else
                    return 0;
            } else {
                return 0;
            }
        }

        return 0;
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high) {
            int mid = low + (high-low) / 2;

            // If this is the number
            int checkCond = checkIncrDecrOrThis(nums, mid, n);
            if(checkCond == 0) {            // This is the peak
                return mid;
            } else if(checkCond == 1) {     // Increasing
                low = mid + 1;
            } else {                        // Decreasing
                high = mid-1;
            }
        }

        return 0;
    }
};