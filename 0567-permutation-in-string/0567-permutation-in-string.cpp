class Solution {
public:
    bool checkZero(vector<int> &vect) {
        for(int i : vect)
            if(i != 0)      return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        
        // Substring to be found has > length than the string, so not possible
        if(len1 > len2)     return false;
        
        // Count the chars in 's1'
        vector<int> cnt(26, 0);
        for(char ch : s1)
            ++cnt[ch-'a'];
        
        for(int i = 0; i < len1; ++i)
            --cnt[s2[i]-'a'];
        
        if(checkZero(cnt))      return true;
        
        for(int i = len1; i < len2; ++i) {
            ++cnt[s2[i-len1]-'a'];
            --cnt[s2[i]-'a'];
            
            if(checkZero(cnt))      return true;
        }
        
        return false;
    }
};