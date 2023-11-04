class Solution {
public:
    bool haveKSmaller(vector<int>& nums, int dist, int k, int n)
    {
        int i = 0, j = 0, cnt = 0;
        
        while(i < n  or  j < n)
        {
            // Increase faster pointer
            while(j < n  and  nums[j]-nums[i] <= dist)
                ++j;
            
            // Now all the pairs in range [i,j] have difference < 'dist'
            cnt += j - i - 1;
            
            ++i;    // Increase slower index
        }
        
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums[n-1] - nums[0];
        
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(haveKSmaller(nums, mid, k, n))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};