class Solution {
public:
    int cntSubarrays(vector<int>& nums, int& mxSum) {
        int currSum = 0, cnt = 1;

        for(int num : nums) {
            if(currSum + num > mxSum) {
                currSum = num;
                ++cnt;
            } else {
                currSum += num;
            }
        }

        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), low = 0, high = 0, res = 0;
        for(int i : nums) {
            high += i;
            low = max(low, i);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cntSubs = cntSubarrays(nums, mid);

            if(cntSubs <= k) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};