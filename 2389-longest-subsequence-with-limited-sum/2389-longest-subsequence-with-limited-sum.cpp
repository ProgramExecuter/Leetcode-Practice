class Solution {
public:
    // Function for finding the highest 'idx' where reqSum <= preSum[idx]
    int findIdx(int &reqSum, vector<int> &preSum) {
        int low = 0, high = preSum.size()-1;
            
        while(low < high) {
            int mid = (low + high + 1) / 2;
            
            if(preSum[mid] > reqSum)
                high = mid-1;
            else
                low = mid;
        }
        
        if(preSum[low] > reqSum)
            return -1;
        
        return low;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        // The logic here is to sort the array, so we get the smaller elements
        // at the start, then we can create longest subsequence for a target sum
        // using the smallest elements, then we calculate the prefix-sum till each
        // index(to reduce time complexity), then we find the result using binary
        // search on each query(target sum)
        
        sort(nums.begin(), nums.end());
        
        vector<int> preSum, res;
        int sum = 0;
        
        // Calculate the prefix sum until each index
        for(int num : nums) {
            sum += num;
            preSum.push_back(sum);
        }
        
        for(int reqSum : queries) {
            int currRes = findIdx(reqSum, preSum) + 1;
            res.push_back(currRes);
        }
        
        return res;
    }
};