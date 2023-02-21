class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            cout << low << " " << high << endl;
//             if(mid == 0) {
                
//             }
//             else if(mid == n-1) {
                
//             }
            // else {
                if(nums[mid-1] != nums[mid] and nums[mid+1] != nums[mid])
                    return nums[mid];
                else {
                    int numEle = mid + 1;
                    
                    if(nums[mid-1] == nums[mid]) {
                        if(numEle % 2)      high = mid-2;
                        else                low = mid+1;
                    }
                    else {
                        if(numEle % 2)      low = mid+2;
                        else                high = mid-1;
                    }
                }
            // }
        }
        
        return nums[low];
    }
};