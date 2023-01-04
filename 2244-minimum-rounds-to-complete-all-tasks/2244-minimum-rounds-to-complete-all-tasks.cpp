class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Map the task level and its count
        map<int, int> mp;
        
        for(int task : tasks)
            ++mp[task];
        
        int reqMinRounds = 0;
        for(auto i : mp) {
            // Only appeared 1 time, so not possible to complete
            if(i.second == 1)   return -1;
            else                reqMinRounds += (i.second + 2)/3;
        }
        
        return reqMinRounds;
    }
};