class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        
        for(int i = 0; i < n; ++i) {
            map<long double, int> mp;
            int samePoint = 1;
            
            for(int j = i+1; j < n; ++j) {
                if(points[i][0] == points[j][0]  and  points[i][1] == points[j][1])
                    ++samePoint;
                else if(points[i][0] == points[j][0])
                    ++mp[INT_MAX];
                else {
                    long double dY = (long double)(points[j][1] - points[i][1]);
                    long double dX = (long double)(points[j][0] - points[i][0]);
                    long double slope = dY / dX;
                    ++mp[slope];
                }
            }
            
            int localMax = samePoint, mxPoints = 0;
            for(auto i : mp)        mxPoints = max(mxPoints, i.second);
            localMax += mxPoints;
            res = max(res, localMax);
        }
        
        return res;
    }
};