class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presumCntMap;
        int sum = 0, res = 0;

        for(int num : nums) {
            sum += num;
            if(sum == k) { ++res; }
            
            res += presumCntMap[sum-k];
            presumCntMap[sum] += 1;
        }

        return res;
    }
};