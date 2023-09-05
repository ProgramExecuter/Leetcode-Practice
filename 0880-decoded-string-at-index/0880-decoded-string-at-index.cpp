class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len = 0;
        int idx = 0;
        
        for(; len < k; ++idx) {
            if(s[idx] >= '0' and s[idx] <= '9')
                len *= (s[idx]-'0');
            else
                ++len;
        }
        
        while(idx--) {
            if(s[idx] >= '0' and s[idx] <= '9')
               len /= (s[idx]-'0'),  k %= len;
            else if(k % len-- == 0)
               return string(1,s[idx]);
        }
        
        return  "none";
    }
};