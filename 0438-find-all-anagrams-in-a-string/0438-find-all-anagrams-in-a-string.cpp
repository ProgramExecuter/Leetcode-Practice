class Solution {
public:
    bool checkZero(vector<int> &arr) {
        for(int i : arr)
            if(i != 0)      return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int lenS = s.size(), lenP = p.size();
        
        vector<int> cnt(26, 0), res;
        
        // Not possible to have any solution
        if(lenP > lenS)     return res;
        
        for(char ch : p)
            ++cnt[ch-'a'];
        
        for(int i = 0; i < s.size(); ++i) {
            --cnt[s[i]-'a'];
            
            // Remove the previous windows's first element, so we can enter next window
            if(i >= lenP)
                ++cnt[s[i-lenP]-'a'];
            
            // We found the one of result, push starting idx of current window to 'res'
            if(checkZero(cnt))
                res.push_back(i-lenP+1);
        }
        
        return res;
    }
};