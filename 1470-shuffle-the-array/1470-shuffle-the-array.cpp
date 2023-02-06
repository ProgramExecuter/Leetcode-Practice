class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        queue<int> q;
        q.push(nums[1]);
        nums[1] = nums[n];
        
        int i = 2, j = n+1;
        while(j < 2*n) {
            int curr = q.front();       q.pop();
            
            if(i < n)       q.push(nums[i]);
            if(i+1 < n)     q.push(nums[i+1]);
            
            nums[i] = curr;
            nums[i+1] = nums[j];
            
            i += 2;     ++j;
        }
        
        return nums;
    }
};