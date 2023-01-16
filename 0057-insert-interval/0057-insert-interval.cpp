class Solution {
public:
    // Check if 2 intervals are overlapping
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
                // Overlapping intevals
                if(isOverlap(intervals[i], newInterval)) {
                    // Merge the overlapping intervals
                    while(i < n  and  isOverlap(intervals[i], newInterval)) {
                        currSt = min(currSt, min(intervals[i][0], newInterval[0]));
                        currEn = max(currEn, max(intervals[i][1], newInterval[1]));
                        ++i;
                    }
                    
                    --i;  // To make up for last ++i
                    isDone = true;      // new interval added
                }
                // The current interval is > than new interval, so directly add it to res
                else if(intervals[i][0] > newInterval[0]) {
                    res.push_back(newInterval);
                    isDone = true;      // new interval added
                }
            }
            
            // Push the interval to result
            res.push_back({currSt, currEn});
            ++i;
        }
        
        // In case the new interval is not added, even after exhausting the intervals
        if(!isDone)     res.push_back(newInterval);
        
        return res;
    }
};