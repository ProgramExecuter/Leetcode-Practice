class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        for(auto interval : intervals) {
            // New interval
            if(res.empty() || (!res.empty() && interval[0] > res.back()[1])) {
                res.push_back(interval);
                continue;
            }

            if(res.back()[1] < interval[1])     res.back()[1] = interval[1];
        }

        return res;
    }
};