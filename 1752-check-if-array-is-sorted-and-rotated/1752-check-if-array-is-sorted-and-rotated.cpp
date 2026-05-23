class Solution {
public:
    bool check(vector<int>& nums) {
        int minIdx = -1, n = nums.size(), minNum = INT_MAX;

        // Find Minimum element index
        for(int i = n-1; i >= 0; --i) {
            if(nums[i] <= minNum) {
                minNum = nums[i];
                minIdx = i;
            } else {
                break;
            }
        }

        int prevIdx = minIdx, startIdx = minIdx, currIdx = (minIdx+1) % n;
        // Check if the array is sorted
        while(currIdx != startIdx) {
            if(nums[currIdx] < nums[prevIdx]) {
                return false;
            }
            prevIdx = currIdx;
            currIdx = (currIdx+1) % n;
        }

        return true;
    }
};