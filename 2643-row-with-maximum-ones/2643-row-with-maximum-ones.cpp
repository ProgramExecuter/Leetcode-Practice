class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int mxCnt = -1, resIdx = -1;

        for(int row = 0; row < mat.size(); ++row) {
            int cnt = 0;
            for(int col = 0; col < mat[row].size(); ++col)
                if(mat[row][col])   ++cnt;
            
            if(mxCnt < cnt) {
                resIdx = row;
                mxCnt = cnt;
            }
        }

        return {resIdx, mxCnt};
    }
};