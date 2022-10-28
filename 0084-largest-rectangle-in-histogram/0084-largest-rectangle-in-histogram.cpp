class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        
        // Left boundary for element
        vector<int> leftSmall(n, 0);
        stack<int> st;
        
        for(int i = 0; i < n; ++i) {
            // Calculate area for greater elements
            // and remove them from stack
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int idx = st.top();
                int lB = leftSmall[idx], rB = i-1;
                
                // Calculate area
                int area = (rB - lB + 1) * heights[idx];
                res = max(res, area);
                
                st.pop();
            }
            
            // Assign left-boundary
            if(!st.empty())     leftSmall[i] = st.top()+1;
            
            st.push(i);
        }
        
        // Calculate the remaining elements in stack
        while(!st.empty()) {
            int idx = st.top();
            int lB = leftSmall[idx], rB = n-1;

            // Calculae the area
            int area = (rB - lB + 1) * heights[idx];
            res = max(res, area);
            
            st.pop();
        }
        
        return res;
    }
};