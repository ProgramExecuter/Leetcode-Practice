class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // 'cntYourTrust' contains the count of people that trust you
        // 'cntYouTrust' contains the count of people that you trust
        vector<int> cntYourTrust(n, 0), cntYouTrust(n, 0);
        for(auto i : trust) {
            ++cntYouTrust[i[0]-1];
            ++cntYourTrust[i[1]-1];
        }
        
        // Check if there is a person that trusts no-one, but everyone trust him
        for(int i = 0; i < n; ++i) {
            if(cntYouTrust[i] == 0  and  cntYourTrust[i] == n-1)
                return i+1;
        }
        
        // Did not find then judge
        return -1;
    }
};