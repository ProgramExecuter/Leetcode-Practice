class Solution {
public:
    string convert(string s, int nR) {
        vector<vector<char>> tmpRes(nR, vector<char>());
        int nC = s.size(), idx = 0;
        
        while(idx < nC) {
            int i = 0;
            
            while(idx < nC  and  i < nR)
                tmpRes[i++].push_back(s[idx++]);
            
            i = nR-2;
            while(idx < nC  and  i > 0)
                tmpRes[i--].push_back(s[idx++]);
        }
        
        string res;
        for(auto i : tmpRes)
            for(auto j : i)
                res += j;
        
        return res;
    }
};