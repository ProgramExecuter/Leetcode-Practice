class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid = 0;
        int st = high+1, en = -1;
        
        // Find first index of 'target'
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(nums[mid] == target)
            {
                if(mid < st)    st = mid;
                high = mid-1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        low = 0, high = nums.size()-1;
        // Find last index of 'target'
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(nums[mid] == target)
            {
                if(mid > en)    en = mid;
                low = mid+1;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        if(en == -1)
            return {-1,-1};
        
        return {st, en};
    }
};