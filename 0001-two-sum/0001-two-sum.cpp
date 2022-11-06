class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for(int i = 0; i < nums.size(); ++i) {
            // Check if this number's counterpart sum is present in map
            if(mp.find(target-nums[i]) != mp.end())
                return {i, mp[target-nums[i]]};
            
            // Put this element in map
            mp[nums[i]] = i;
        }
        
        return {0, 0};
    }
};