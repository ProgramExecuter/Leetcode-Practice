class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int resIdx = -1, low = 0, high = nums.size() - 1;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        
        if(nums[low] < target)
            return low + 1;
        
        return low;
    }
};