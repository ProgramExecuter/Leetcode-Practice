class Solution {
public:
    bool isPalin(string s, int st, int en) {
        for(int i = st, j = en; i < j; ++i, --j) {
            if(s[i] != s[j])    return false;
        }
        return true;
    }
    void f(string &s, int st, vector<vector<string>> &ans, vector<string> &curr) {
        if(st == s.size()) {
            ans.push_back(curr);
            return;
        }

        for(int i = st; i < s.size(); ++i) {
            if(!isPalin(s, st, i))  continue;
            
            curr.push_back(s.substr(st,(i-st+1)));
            f(s, i+1, ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        
        f(s, 0, ans, curr);
        return ans;
    }
};