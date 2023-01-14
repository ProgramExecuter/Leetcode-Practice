class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        res.push_back(pref[0]);
        
        // Since a ^ b ^ c = (a ^ b) ^ c
        // So, (a ^ b ^ c) ^ (a ^ b) => c
        // Since, duplicates cancel out, we get 'c', same can be applied here
        for(int i = 1; i < pref.size(); ++i)
            res.push_back(pref[i] ^ pref[i-1]);
        
        return res;
    }
};