class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN, currProd = 1;

        // Calculate Prefix Product, Suffix Product
        // While keeping in mind that each zero divides the array into parts
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {         // Zero
                currProd = 1;
            } else {
                currProd *= nums[i];
                res = max(res, currProd);
            }
            res = max(res, nums[i]);
        }

        currProd = 1;
        for(int i = n-1; i >= 0; --i) {
            if(nums[i] == 0) {         // Zero
                currProd = 1;
            } else {
                currProd *= nums[i];
                res = max(res, currProd);
            }
        }

        return res;
    }
};