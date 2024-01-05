class Solution {
public:
    int lb(vector<int> &arr, int len, int tar) {            // Finding lower-bound of target in array
        int low = 0, high = len-1;

        while(low < high) {
            int mid = low + (high-low)/2;

            if(arr[mid] < tar)
                low = mid+1;
            else
                high = mid;
        }

        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lcsArr;

        for(int i = 0; i < n; ++i) {                        // Visit each element
            int len = lcsArr.size();
            
            if(len == 0  ||  lcsArr[len-1] < nums[i]) {     // If this element is > last lcsArr's
                lcsArr.push_back(nums[i]);                  // element, then push it into 'lcsArr'
            }
            else {                                          // Else find lower-bound of current
                int idx = lb(lcsArr, len, nums[i]);         // element, and insert it there
                lcsArr[idx] = nums[i];
            }
        }
        
        return lcsArr.size();                               // Return the LCS size
    }
};