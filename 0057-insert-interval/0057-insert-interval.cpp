class Solution {
public:
    bool isOverlap(vector<int> &interval1, vector<int> &interval2) {
        return (
            !(interval1[0] > interval2[1]) and 
            !(interval1[1] < interval2[0])
            );
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), i = 0;
        bool isDone = false;
        
        while(i < n) {
            int currSt = intervals[i][0];
            int currEn = intervals[i][1];
            
            if(!isDone) {
                // Overlapping with new interval, i.e => new interval's starting is not
                // greater than intervals's ending  AND  new intervals's ending is not
                // greater than intervals's starting
                if(isOverlap(intervals[i], newInterval)) {
                    while(i < n  and  isOverlap(intervals[i], newInterval)) {
                        currSt = min(currSt, min(intervals[i][0], newInterval[0]));
                        currEn = max(currEn, max(intervals[i][1], newInterval[1]));
                        ++i;
                    }
                    --i;
                    isDone = true;
                }
                else if(intervals[i][0] > newInterval[0]) {
                    res.push_back(newInterval);
                    isDone = true;
                }
            }
            
            // Push the interval to result
            res.push_back({currSt, currEn});
            ++i;
        }
        
        if(!isDone)     res.push_back(newInterval);
        
        return res;
    }
};