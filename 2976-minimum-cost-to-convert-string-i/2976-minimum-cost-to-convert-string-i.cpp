class Solution {
public:
    vector<long long> findMinDistToAll(int charIdx, vector<vector<pair<int, long long>>> &adjMat) {
        // Distance array
        vector<long long> distArr(26, -1);
        distArr[charIdx] = 0;

        // Set of {distance, charIdx}
        set<pair<long long, int>> distChar;
        distChar.insert({0, charIdx});

        while(!distChar.empty()) {
            // Find the top element
            auto topEle = *distChar.begin();
            long long dist = topEle.first;
            int currChar = topEle.second;
            distChar.erase(distChar.begin());

            // Adjacency Matrix
            // Vector of pairs of {node, dist} for each character

            // Loop adjacent elements
            for(auto curr : adjMat[currChar]) {
                long long newDist = 0ll + dist + curr.second;
                if(distArr[curr.first] == -1  ||  distArr[curr.first] > newDist) {
                    distArr[curr.first] = newDist;
                    distChar.insert({(newDist), curr.first});
                }
            }
        }

        return distArr;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> charDist;
        int len = original.size(), lenSrc = source.size();
        long long res = 0ll;

        // Adjacency Matrix
        // Vector of pairs of {node, dist} for each character
        vector<vector<pair<int, long long>>> adjMat(26, vector<pair<int, long long>>());
        for(int i = 0; i < len; ++i) {
            adjMat[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
        }

        for(int i = 0; i < 26; ++i) {
            charDist.push_back(findMinDistToAll(i, adjMat));
        }

        for(int i = 0; i < lenSrc; ++i) {
            int oldCharIdx = source[i]-'a';
            int newCharIdx = target[i]-'a';

            if(charDist[oldCharIdx][newCharIdx] == -1) { return -1; }

            res += charDist[oldCharIdx][newCharIdx];
        }

        return res;
    }
};