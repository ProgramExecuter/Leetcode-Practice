class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cntProvince = 0;
        int n = isConnected.size();
        queue<int> travQ;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; ++i) {
            if(vis[i])      continue;
            ++cntProvince;
            travQ.push(i);
            vis[i] = true;

            while(!travQ.empty()) {
                int curr = travQ.front();
                travQ.pop();

                for(int j = 0; j < n; ++j) {
                    if(isConnected[curr][j]) {
                        if(vis[j])      continue;
                        travQ.push(j);
                        vis[j] = true;
                    }
                }
            }
        }

        return cntProvince;
    }
};