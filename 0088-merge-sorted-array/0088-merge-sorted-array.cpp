class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mIdx = m-1, idx = m+n-1, nIdx = n-1;

        while(nIdx >= 0) {
            if(mIdx >= 0  &&  nums2[nIdx] < nums1[mIdx]) {
                nums1[idx] = nums1[mIdx];
                --mIdx;
            } else {
                nums1[idx] = nums2[nIdx];
                --nIdx;
            }
            --idx;
        }
    }
};