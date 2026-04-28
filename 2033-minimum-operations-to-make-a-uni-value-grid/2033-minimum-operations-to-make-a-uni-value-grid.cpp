class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flatArr;
        for(auto row : grid) {
            for(auto ele : row)
                flatArr.push_back(ele);
        }

        sort(flatArr.begin(), flatArr.end());

        int len = flatArr.size(), res = 0;
        int median = flatArr[len/2], mod = flatArr[0] % x;

        for(int i = 0; i < len; ++i) {
            if(flatArr[i] % x != mod)   return -1;

            res += abs(flatArr[i]-median) / x;
        }

        return res;
    }
};