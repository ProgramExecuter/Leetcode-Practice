class Solution {
public:
    int minimumDeletions(string s) {
        int numAsFromEnd = 0, numBsFromStart = 0;
        int n = s.size();
        
        for(int i = 0; i < n; ++i)
            if(s[i] == 'a')     ++numAsFromEnd;
        
        int res = n;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == 'a')     --numAsFromEnd;
            
            res = min(res, numAsFromEnd + numBsFromStart);
            
            if(s[i] == 'b')     ++numBsFromStart;
        }
        
        return res;
    }
};