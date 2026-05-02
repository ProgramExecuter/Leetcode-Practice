class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        double res = 0.0;
        int eleNeed = (m + n + 1) / 2;

        if(m > n)
            return findMedianSortedArrays(nums2, nums1);

        if(m == 0) {
            int midTmp = (n+1) / 2;
            if(n % 2)
                return nums2[midTmp-1];
            else
                return (nums2[midTmp-1] + nums2[midTmp]) / 2.0;
        }

        int low = 0, high = m;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int cnt2 = eleNeed - mid;
            // Take mid elements for the left half from nums1
            // and (eleNeed - mid) for the right half from nums2

            int l1 = mid-1 >= 0 ? nums1[mid-1] : INT_MIN;
            int l2 = cnt2-1 >= 0 && cnt2-1 < n ? nums2[cnt2-1] : INT_MIN;
            int r1 = mid < m ? nums1[mid] : INT_MAX;
            int r2 = cnt2 < n ? nums2[cnt2] : INT_MAX;

            cout << "[low=" << low << ", high=" << high  << ", mid=" << mid << ", cnt2=" << cnt2 
            << ", l1=" << l1 << ", l2=" << l2 << ", r1=" << r1 << ", r2=" << r2 << "]" << endl;

            if(l1 <= r2  &&  l2 <= r1) {
                if((m+n) % 2 == 0)
                    return ((max(l1, l2) + min(r1, r2)) / 2.0);
                else
                    return max(l1, l2);
            } else if(l1 > r2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return res;
    }
};