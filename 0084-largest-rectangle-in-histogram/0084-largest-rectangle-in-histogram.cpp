class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0, i = 0;
        
        stack<int> st;
        
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
};