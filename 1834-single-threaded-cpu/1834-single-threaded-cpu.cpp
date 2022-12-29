class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& task) {
        int currTime = 1, idx = 0, n = task.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> res;        vector<vector<int>> tasks;
        
        // Sort the array
        for(int i = 0; i < n; ++i) {
            vector<int> tmp;
            tmp.push_back(task[i][0]);
            tmp.push_back(task[i][1]);
            tmp.push_back(i);
            tasks.push_back(tmp);
        }
        sort(tasks.begin(), tasks.end());
        
        while(idx < n) {
            if(currTime < tasks[idx][0]  and  q.empty())
                currTime = tasks[idx][0];
            
            while(idx < n  and  currTime >= tasks[idx][0]) {
                q.push({tasks[idx][1], tasks[idx][2]});
                ++idx;
            }
            
            currTime += q.top().first;
            res.push_back(q.top().second);
            q.pop();
        }
        
        while(!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        
        return res;
    }
};