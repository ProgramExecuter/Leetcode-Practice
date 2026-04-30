class Solution {
public:
    int findDividedBySum(vector<int>& nums, int divisor) {
        int cnt = 0;

        for(int i : nums) {
            cnt += ceil((1.0*i)/divisor);
        }

        return cnt;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 1, res = 0;
        for(int i : nums)   high = max(high, i);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int divSum = findDividedBySum(nums, mid);

            if(divSum <= threshold) {
                res = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return res;
    }
};