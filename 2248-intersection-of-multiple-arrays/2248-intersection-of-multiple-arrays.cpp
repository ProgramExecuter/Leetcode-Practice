class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> numCnt;
        
        // Calculate the count of each element from each array
        for(auto arr : nums) {
            for(int i : arr)
                ++numCnt[i];
        }
        
        vector<int> res;
        int n = nums.size();
        // We add the element in 'res' if it occured 'n' times, since
        // each element occurs only once in each nums[i]
        for(auto i : numCnt)
            if(i.second == n)   res.push_back(i.first);
        
        return res;
    }
};