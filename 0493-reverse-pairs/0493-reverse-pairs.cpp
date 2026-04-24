class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int en, int &res) {
        int idx1 = 0, idx2 = 0, idx = st;
        int len1 = mid-st+1, len2 = en-mid;
        vector<int> left(nums.begin()+st, nums.begin()+mid+1);
        vector<int> right(nums.begin()+mid+1, nums.begin()+en+1);

        while(idx1 < len1  &&  idx2 < len2) {
            // Condition Met
            if(1ll*left[idx1] > 1ll*2*right[idx2]) {
                res += len1-idx1;
                ++idx2;
            } else {
                ++idx1;
            }
        }

        idx1 = 0;   idx2 = 0;
        while(idx1 < len1  &&  idx2 < len2) {
            // Condition Met
            if(left[idx1] < right[idx2]) {
                nums[idx++] = left[idx1++];
            } else {
                nums[idx++] = right[idx2++];
            }
        }

        // Check for remaining elements
        while(idx1 < len1) {
            nums[idx++] = left[idx1++];
        }
        while(idx2 < len2) {
            nums[idx++] = right[idx2++];
        }
    }
    void mergeSort(vector<int>& nums, int st, int en, int& res) {
        if(st >= en)    return;
        int mid = st + ((en-st)/2);

        mergeSort(nums, st, mid, res);
        mergeSort(nums, mid+1, en, res);
        merge(nums, st, mid, en, res);
    }
    int reversePairs(vector<int>& nums) {
        int len = nums.size(), res = 0;
        mergeSort(nums, 0, len-1, res);

        return res;
    }
};