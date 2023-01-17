class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevCnt = 0, beamCnt = 0;
        
        // Check for each row
        for(int i = 0; i < bank.size(); ++i) {
            int currCnt = 0;
            
            // Count the security devices in this row
            for(char ch : bank[i])
                if(ch == '1')   ++currCnt;
            
            // Now the beamCnt is incremented by (prevCnt*currCnt), since this is no. of
            // beams coming from this row to some other lower row
            beamCnt += (prevCnt * currCnt);
            
            // If the current count of sec. devices > 0, then it is recorded for the next
            // row which will have security devices, and we multiply them to get beam cnt
            if(currCnt > 0)     prevCnt = currCnt;
        }
        
        // Return the beam count
        return beamCnt;
    }
};