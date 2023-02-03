class Solution {
public:
    string convert(string s, int nR) {
        if(nR == 1)     return s;
        int nC = s.size(), idx = 0;
        
        string res;
        for(int idx = 0; idx < nR; ++idx) {
            int i = idx;
            
            while(i < nC) {
                // Add the normal top-down char
                res += s[i];
                
                // Add the zig-zag char
                if(idx > 0  and  idx < nR-1) {
                    int currIdx = i + (nR - idx - 1) * 2;
                    if(currIdx >= 0  and  currIdx < nC)
                        res += s[currIdx];
                }
                
                i += (2*nR - 2);
            }
        }
        
        return res;
    }
};