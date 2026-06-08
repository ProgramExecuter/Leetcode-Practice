class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> res, inDeg(numCourses, 0);
        queue<int> travQ;
        
        // Create adjacency list and also track indegree of nodes
        for(auto curr : prerequisites) {
            adjList[curr[1]].push_back(curr[0]);
            ++inDeg[curr[0]];
        }
        
        // If there are nodes with inDegree 0, then push them
        // into queue, since they are nodes which can be put at start
        // of result, since they don't come before or after nodes
        for(int i = 0; i < numCourses; ++i) {
            if(inDeg[i] == 0)   travQ.push(i);
        }
        
        while(!travQ.empty()) {
            int curr = travQ.front();
            travQ.pop();
            
            // Current node to be put in result
            // since it has inDegree = 0
            res.push_back(curr);
            
            for(int adj : adjList[curr]) {
                --inDeg[adj];
                if(inDeg[adj] == 0)
                    travQ.push(adj);
            }
        }

        if(res.size() != numCourses)
            return {};
        
        return res;
    }
};