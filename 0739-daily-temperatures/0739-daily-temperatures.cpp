class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = temp.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; ++i) {
            int currTemp = temp[i];
            
            // We produce result for the idx, whom to which we got warmer temp.
            while(!st.empty()  and  st.top().second < currTemp) {
                int idx = st.top().first;
                st.pop();
                
                ans[idx] = (i - idx);
            }
            
            st.push({i, currTemp});
        }
        
        return ans;
    }
};