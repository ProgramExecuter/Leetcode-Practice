auto _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> presumCntMap;
        presumCntMap[0] = 1;
        int sum = 0, res = 0;

        for(int num : nums) {
            sum += num;            
            res += presumCntMap[sum-k];
            presumCntMap[sum] += 1;
        }

        return res;
    }
};