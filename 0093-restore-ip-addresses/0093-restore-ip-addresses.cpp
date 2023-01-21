class Solution {
public:
    void f(int idx, string curr, int &cnt, string &s, vector<string> &res) {
        int n = s.size();
        
        if(idx == n) {
            if(cnt == 4)
                res.push_back(curr);
            return;
        }
        else if(idx > n)
            return;
        else
            if(cnt == 4)    return;
        
        string tmpStr = "";
        
        // Take 1 length
        tmpStr = curr + s[idx];
        if(cnt++ < 3)     tmpStr += '.';
        f(idx+1, tmpStr, cnt, s, res);
        --cnt;
        
        // Take 2 length
        if(s[idx] != '0') {
            tmpStr = curr + s.substr(idx, 2);
            if(cnt++ < 3)     tmpStr += '.';
            f(idx+2, tmpStr, cnt, s, res);
            --cnt;
        }
        
        // Take 3 length
        if(stoi(s.substr(idx, 2)) >= 10  and  stoi(s.substr(idx, 3)) <= 255) {
            tmpStr = curr + s.substr(idx, 3);
            if(cnt++ < 3)     tmpStr += '.';
            f(idx+3, tmpStr, cnt, s, res);
            --cnt;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int cnt = 0;
        f(0, "", cnt, s, res);
        
        return res;
    }
};