class Solution {
public:
    bool check(int idx, int prevParIdx, int nPar, string &s, unordered_set<string> &st) {
        string toBePar = s.substr(prevParIdx+1, idx-prevParIdx);
        bool par = false, noPar = false;
        bool isParInSet = st.find(toBePar) != st.end();
        int n = s.size();

        // We have to make these partition, no other option
        if(idx == n-1)
            return isParInSet;
        else if(idx == n-2  and  nPar == 0) {
            if(isParInSet)
                par = check(idx+1, idx, nPar+1, s, st);
            return par;
        }
        
        // Partition here
        if(isParInSet)
            par = check(idx+1, idx, nPar+1, s, st);
        
        // No Partition here
        noPar = check(idx+1, prevParIdx, nPar, s, st);
        
        return par or noPar;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Used for mapping 'length_of_string' to a set of string having that length
        unordered_set<string> st;
        int minLen = INT_MAX;
        
        for(string s : words) {
            int len = s.size();
            minLen = min(minLen, len);
            st.insert(s);
        }
        
        vector<string> res;
        for(string s : words) {
            int len = s.size();
            if(len == minLen)    continue;
            
            // Check if this string can be partitioned into multiple
            // strings, which are already present in the set(map)
            if(check(0, -1, 0, s, st))
                res.push_back(s);
        }
        
        return res;
    }
};