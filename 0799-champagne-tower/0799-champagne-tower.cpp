class Solution {
public:
    double champagneTower(int poured, int qRow, int qCol) {
        vector<double> currRow(1, poured);
        
        for(int i = 0; i <= qRow; ++i) {
            vector<double> nextRow(i+2, 0.0);
            for(int j = 0; j <= i; ++j) {
                if(currRow[j] > 1) {
                    double extra = currRow[j]-1;
                    nextRow[j] += extra / 2;
                    nextRow[j+1] += extra / 2;
                    currRow[j] = 1.0;
                }
            }
            
            if(i != qRow)   currRow = nextRow;
        }
        
        return currRow[qCol];
    }
};