class Solution {
public:
    long long maxPoints(vector<vector<int>>& points)
    {
        int nRow = points.size(), nCol = points[0].size();
        vector<long long> prevRow(points[0].begin(), points[0].end());
        
        for(int row = 1; row < nRow; ++row)
        {
            vector<long long> currRow(points[row].begin(), points[row].end());
            vector<long long> left(nCol, 0), right(nCol, 0);
            
            left[0] = prevRow[0];
            for(int i = 1; i < nCol; ++i)
                left[i] = max(left[i-1] - 1, 0ll + prevRow[i]);
            
            right[nCol-1] = prevRow[nCol-1];
            for(int i = nCol-2; i >= 0; --i)
                right[i] = max(right[i+1] - 1, 0ll + prevRow[i]);
            
            for(int i = 0; i < nCol; ++i)
                currRow[i] += max(left[i], right[i]);
            
            prevRow = currRow;
        }
        
        long long res = 0ll;
        for(int i = 0; i < nCol; ++i)
            res = max(prevRow[i], res);
        
        return res;
    }
};