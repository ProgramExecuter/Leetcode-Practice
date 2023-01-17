class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        // Used two 1-D vectors for which is equivalent to O(1)
        // So optimized space from O(N) to O(1)
        vector<int> next(2, 0), curr(2, 0);
        
        // Bottom-Up DP(Iterative approach)
        for(int idx = n-1; idx >= 0; --idx) {
            for(int prevCh = 0; prevCh <= 1; ++prevCh) {
                int flip = 1e9, noFlip = 1e9;
                
                if(s[idx] == '0') {
                    // Previous is '1', so we must flip and make this '1'
                    if(prevCh == 1) {
                        flip = 1 + next[1];
                    }
                    // Previous is '0', so we can flip or not flip it
                    else {
                        flip = 1 + next[1];
                        noFlip = next[0];
                    }
                }
                else {
                    // Since the previous char is '1', we must make this '1'
                    if(prevCh == 1) {
                        noFlip = next[1];
                    }
                    // Previous char is '0', so we can flip or not flip
                    else {
                        flip = 1 + next[0];
                        noFlip = next[1];
                    }
                }
                
                curr[prevCh] = min(flip, noFlip);
            }
            
            next = curr;
        }
        
        return next[0];
    }
};