class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRowCnt = 0, totalBeams = 0;
        
        for(string row : bank)
        {
            int currRowCnt = 0;
            for(char ch : row)
                if(ch == '1')   ++currRowCnt;
            
            totalBeams += prevRowCnt * currRowCnt;
            
            if(currRowCnt > 0)
                prevRowCnt = currRowCnt;
        }
        
        return totalBeams;
    }
};
