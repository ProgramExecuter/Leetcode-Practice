class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int st = 0, en = nums.size()-1;
        
        while(st < en) {
            if(nums[st] % 2 == 0) { ++st;   continue; }
            if(nums[en] % 2 == 1) { --en;   continue; }
            
            swap(nums[st], nums[en]);
            ++st;   --en;
        }
        
        return nums;
    }
};