class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0, sum = 0, prev = 0;
        
        for(int num : nums) {
            if(num <= prev)     sum = 0;
            
            sum += num;     prev = num;
            res = max(res, sum);
        }
        
        return res;
    }
};