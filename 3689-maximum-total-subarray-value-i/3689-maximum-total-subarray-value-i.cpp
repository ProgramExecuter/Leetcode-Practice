class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = INT_MAX, mx = INT_MIN;

        for(int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }

        return 1ll*k*(mx-mn);
    }
};