class Solution {
public:
    string convert(string s, int nR) {
        vector<vector<char>> tmpRes(nR, vector<char>());
        int nC = s.size(), idx = 0;
        
        // Iterate the string
        while(idx < nC) {
            int i = 0;
            
            // Add the normal top-down characters in each row
            while(idx < nC  and  i < nR)
                tmpRes[i++].push_back(s[idx++]);
            
            // Add the diagonal(zig-zag) chars starting from 2nd last row to 2nd row 
            i = nR-2;
            while(idx < nC  and  i > 0)
                tmpRes[i--].push_back(s[idx++]);
        }
        
        // Create the result
        string res;
        for(auto i : tmpRes)
            for(auto j : i)     res += j;
        
        return res;
    }
};