class Solution {
public:
    class DisjointSet {
        vector<int> rank, parent;
    public:
        DisjointSet(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node != parent[node])
                parent[node] = findUPar(parent[node]);
            return parent[node];
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int len = source.size();
        DisjointSet dj(len);

        for(auto link : allowedSwaps) {
            dj.unionByRank(link[0], link[1]);
        }

        map<int, map<int, int>> parToEleCnt;

        for(int i = 0; i < len; ++i) {
            int par = dj.findUPar(i);
            ++parToEleCnt[par][source[i]];

            // if(parToEleCnt.find(par) == parToEleCnt.end()) {
            //     map<int, int> tmp;      ++tmp[source[i]];    ++tmp[source[par]];
            //     parToEleCnt[par] = tmp;
            // } else {
            //     ++parToEleCnt[par][source[i]];
            // }
        }

        int res = 0;
        for(int i = 0; i < len; ++i) {
            int par = dj.findUPar(i);

            if(parToEleCnt[par][target[i]] > 0) {
                --parToEleCnt[par][target[i]];
            } else {
                ++res;
            }
        }

        return res;
    }
};