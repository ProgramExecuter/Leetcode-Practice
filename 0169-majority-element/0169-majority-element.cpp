class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr = nums[0], cnt = 1;
        
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == curr)
                ++cnt;
            else
                --cnt;
            
            if(cnt == 0)
            {
                cnt = 1;
                curr = nums[i];
            }
        }
        
        return curr;
    }
};