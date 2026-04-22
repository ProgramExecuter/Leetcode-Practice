class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Put both at same place for SHELL SORT algo
        for(int i = 0; i < n; ++i) {
            nums1[m+i] = nums2[i];
        }

        int gap = ceil((m + n) / 2.0), low = 0, high = 0;
        bool lastGapOnce = true;

        while(lastGapOnce) {
            if(gap == 1)    lastGapOnce = false;
            low = 0, high = gap;
            
            while(high < m+n) {
                if(nums1[low] > nums1[high])    swap(nums1[low], nums1[high]);
                ++low;  ++high;
            }

            gap = ceil(gap / 2.0);
        }
    }
};