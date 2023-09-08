class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        // Create a vector of 1
        // with increasing no. of elements
        for(int i=1; i<=numRows; ++i)
        {
            vector<int> tmp;
            for(int j=1; j<= i; ++j) {
                tmp.push_back(1);
            }
            ans.push_back(tmp);
        }
        
        // Start from 2nd row
        for(int i=2; i<numRows; ++i) {
            for(int j=1; j<i; ++j) {
                // current-element  =  upper-left + upper element
                ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
            }
        }
        
        return ans;
    }
};
