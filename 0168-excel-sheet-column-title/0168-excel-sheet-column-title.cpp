class Solution {
public:
    string convertToTitle(int colNum) {
        string res = "";
        
        while(colNum > 0) {
            --colNum;
            res += 'A' + (colNum % 26);
            colNum /= 26;
        }
        reverse(res.begin(), res.end());
        
        
        return res;
    }
};