class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        /*
            Use Tortoise Hare Method
        */
        int slow = nums[0], fast = nums[0];
        
        
        // Find Cycle
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        slow = nums[0];
        
        // Now move both at same speed
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};