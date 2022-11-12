class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), cnt = 0;
        
        // Calculate remainder for each element after dividing by 60
        vector<int> rem(n, 0);
        
        // Map the no. of occurences of a particular remainder
        map<int, int> mp;
        
        // Iterate through remainder array
        for(int i = 0; i < n; ++i) {
            // Remainder of this song after % by 60
            rem[i] = time[i] % 60;
            
            // IF remainder is 0, then find its equivalent 0
            // Since, %60 only gives [0, 59]
            if(rem[i] == 0) {
                // Found pair, sum up the occurences
                cnt += mp[0];
            }
            else {
                // Found pair, sum up the occurences
                cnt += mp[60-rem[i]];
            }
            
            // Increment the count of occurences of this remainder
            ++mp[rem[i]];
        }
        
        return cnt;
    }
};