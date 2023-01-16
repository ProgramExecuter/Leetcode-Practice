class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, eq = 0, high = 0, n = nums.size();
        
        // count the no. of 'lower' and 'equal' to 'pivot'
        for(int i : nums) {
            if(i < pivot)           ++low;
            else if(i == pivot)     ++eq;
        }
        
        // Index from which these values are to be filled
        high = low + eq;        eq = low;       low = 0;
        
        // Create the result
        vector<int> res(n, 0);
        for(int i : nums) {
            if(i < pivot)       res[low++] = i;
            else if(i > pivot)  res[high++] = i;
            else                res[eq++] = i;
        }
        
        return res;
    }
};