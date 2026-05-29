class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for(int num : nums) {
            int sum = 0;
            while(num) {
                sum += num % 10;
                num /= 10;
            }
            mn = min(mn, sum);
        }

        return mn;
    }
};