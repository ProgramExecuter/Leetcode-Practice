class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int gap = m + n;
        
        for(int i = 0; i < n; ++i)
        {
            nums1[m+i] = nums2[i];
        }
        
        while(gap > 1)
        {
            if(gap % 2)     gap = (gap / 2) + 1;
            else            gap = gap / 2;
            
            int frontIdx = 0, backIdx = gap;
            
            while(backIdx < m+n)
            {
                if(nums1[frontIdx] >= nums1[backIdx])
                    swap(nums1[frontIdx], nums1[backIdx]);
                
                
                ++frontIdx;
                ++backIdx;
            }
        }
    }
};