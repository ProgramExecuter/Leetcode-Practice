class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt1 = 0, cntFlip = 0;
        
        for(char ch : s) {
            // When we encounter 1, we just count it
            if(ch == '1')
                ++cnt1;
            // When we encounter 0, then we check if we flip it or don't if we flip it,
            // then ++cntFlip, and if we don't flip it, then we will have to
            // flip all the 1's we encountered until now, thus we take min(cntFlip, cnt1)
            // 'cntFlip' => flip, 'cnt1' => no flip
            else {
                ++cntFlip;
                cntFlip = min(cntFlip, cnt1);
            }
        }
        
        return cntFlip;
    }
};