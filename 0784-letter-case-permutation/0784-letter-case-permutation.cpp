class Solution {
public:
    void util(int idx, string &curr, string &s, vector<string> &res) {
        if(idx >= s.size()) {
            res.push_back(curr);
            return;
        }
        
        curr += s[idx];
        util(idx+1, curr, s, res);
        curr.pop_back();
        
        if(s[idx] >= 'a'  &&  s[idx] <= 'z') {
            curr += char(s[idx]-32);
            util(idx+1, curr, s, res);
            curr.pop_back();
        }
        else if(s[idx] >= 'A'  &&  s[idx] <= 'Z') {
            curr += char(s[idx]+32);
            util(idx+1, curr, s, res);
            curr.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string curr = "";
        
        util(0, curr, s, res);
        
        return res;
    }
};