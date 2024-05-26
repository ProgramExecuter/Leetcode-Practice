class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());
        int currSt = intervals[0][0], currEn = intervals[0][1];
        
        vector<vector<int>> res;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i][0] > currEn)
            {
                res.push_back({currSt, currEn});
                currSt = intervals[i][0];
                currEn = intervals[i][1];
            }
            else
            {
                currEn = max(currEn, intervals[i][1]);
            }
        }
        res.push_back({currSt, currEn});
        
        
        return res;
    }
};