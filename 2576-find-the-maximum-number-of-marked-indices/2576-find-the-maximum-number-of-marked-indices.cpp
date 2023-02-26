class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        
        int i = 0, j = n/2;
        
        while(i < n/2  and  j < n) {
            if(2*nums[i]  <=  nums[j]) {
                res += 2;
                ++i;    ++j;
            }
            else {
                ++j;
            }
        }
        
        return res;
    }
};