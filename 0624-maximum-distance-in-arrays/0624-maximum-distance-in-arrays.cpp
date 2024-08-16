class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int nRows = arrays.size();
        int biggest = arrays[0][arrays[0].size()-1];
        int smallest = arrays[0][0];
        int res = 0;
        
        for(int i = 1; i < nRows; ++i)
        {
            int currMin = arrays[i][0];
            int currMax = arrays[i][arrays[i].size()-1];
            
            res = max(res, max(abs(smallest - currMax) , abs(biggest - currMin)));
            
            smallest = min(smallest, currMin);
            biggest = max(biggest, currMax);
        }
        
        return res;
    }
};