class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int resIdx = -1, low = 0, high = nums.size() - 1;
        
        // Binary Search
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        
        // If the 'target' is greater than  all the elements, then result idx + 1
        if(nums[low] < target)
            return low + 1;
        
        return low;
    }
};