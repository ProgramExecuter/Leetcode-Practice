class Solution {
public:
    int largestRectangleArea(vector<int>& heights, stack<int> &st) {
        int n = heights.size(), res = 0, i = 0;

        while(i < n || !st.empty()) {
            // Calculate area for greater elements and remove them from stack
            while(
                !st.empty() &&
                ((i < n && heights[st.top()] > heights[i]) ||
                (i == n && !st.empty()))
            ) {
                int idx = st.top();
                st.pop();
                
                int lB = st.empty() ? 0 : st.top()+1;
                int rB = i < n ? i-1 : n-1;
                
                // Calculate area
                int area = (rB - lB + 1) * heights[idx];
                res = max(res, area);
            }
            
            if(i < n)   st.push(i++);
        }
        
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int nRow = matrix.size(), nCol = matrix[0].size(), ans = 0;
        vector<int> height(nCol, 0);
        
        stack<int> st;
        
        for(int row = 0; row < nRow; ++row) {
            // Check for each row
            for(int col = 0; col < nCol; ++col) {
                // Increase or assign height
                if(matrix[row][col] == '1')     ++height[col];
                else                            height[col] = 0;
            }
            
            // Get rectangle with maximum area
            ans = max(ans, largestRectangleArea(height, st));
        }
        
        return ans;
    }
};