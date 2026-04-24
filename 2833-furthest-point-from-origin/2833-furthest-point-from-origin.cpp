class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntLR = 0, cntUnder = 0;
        for(char ch : moves) {
            if(ch == 'L')       ++cntLR;
            else if(ch == 'R')  --cntLR;
            else                ++cntUnder;
        }

        return (abs(cntLR) + cntUnder);
    }
};