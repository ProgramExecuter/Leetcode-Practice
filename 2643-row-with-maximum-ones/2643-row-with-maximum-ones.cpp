class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cnt = 0;
        // {cnt, minIndex} stack
        stack<pair<int, int>> st;

        for(int row = 0; row < mat.size(); ++row) {
            cnt = 0;
            for(int col = 0; col < mat[row].size(); ++col)
                if(mat[row][col])   ++cnt;
            
            if(!st.empty() && st.top().first > cnt)    continue;

            while(!st.empty() && st.top().first < cnt)
                st.pop();
            
            if(st.empty()) {
                st.push({cnt, row});
            }
        }

        return {st.top().second, st.top().first};
    }
};