class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int len = nums.size(), currXor = 0;
        long long res = 0ll;
        unordered_map<int, int> xorCnt;
        xorCnt[0] = 1;

        for(int i = 0; i < len; ++i) {
            currXor ^= nums[i];

            res += xorCnt[currXor]++;
        }

        return res;
    }
};