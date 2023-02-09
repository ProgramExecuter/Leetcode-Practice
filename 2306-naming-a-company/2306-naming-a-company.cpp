class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<set<string>> mp(26, set<string>());
        
        // Map the suffix(except 1st character) with the characters according to their
        // first character
        for(string s : ideas) {
            int idx = s[0] - 'a';
            string sub = s.substr(1);
            mp[idx].insert(sub);
        }
        
        long long res = 0ll;
        
        for(int i = 0; i < 26; ++i) {
            for(int j = i+1; j < 26; ++j) {
                int cnt1 = 0ll, cnt2 = 0ll;
                
                // Find the strings in mp[i] that can be concatenated with mp[j]
                for(auto& s : mp[i]) {
                    if(mp[j].find(s) == mp[j].end())
                        ++cnt1;
                }
                
                // Find the strings in mp[j] that can be concantenated with mp[i]
                for(auto& s : mp[j]) {
                    if(mp[i].find(s) == mp[i].end())
                        ++cnt2;
                }
                
                res += cnt1 * cnt2;
            }
        }
        
        // Since the concatened string can be  A+B  or  B+A
        return res * 2;
    }
};