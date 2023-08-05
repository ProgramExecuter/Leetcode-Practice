class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        map<string, int> mp;
        int res = 0;
        
        for(string s : words) {
            string orgS = s;
            reverse(s.begin(), s.end());
            
            if(mp.find(s) != mp.end()) {
                --mp[s];
                ++res;
            }
            else {
                mp[orgS]++;
            }
        }
        
        return res;
    }
};