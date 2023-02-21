class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        // Binary Search
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            // Found the unique element
            if(nums[mid-1] != nums[mid] and nums[mid+1] != nums[mid])
                return nums[mid];
            else {
                // Number of element until 'mid' index
                int numEle = mid + 1;
                
                if(nums[mid-1] == nums[mid]) {
                    // Ex: 1 1 3 5 5 9 9 =>   'mid' is 4
                    if(numEle % 2)      high = mid-2;
                    // Ex: 1 1 2 2 3 3   =>   'mid' is 3
                    else                low = mid+1;
                }
                else {
                    // Ex: 1 1 3 3 4 5 5 =>   'mid' is 2
                    if(numEle % 2)      low = mid+2;
                    // Ex: 1 1 2 4 4 7 7 =>   'mid' is 3
                    else                high = mid-1;
                }
            }
        }
        
        return nums[low];
    }
};