class Solution {
public:
    bool check(string &str1, string &str2, int idx1, int idx2) {
        if(idx2 == str2.size())     return true;
        if(idx1 == str1.size())     return false;
        
        char nxtCh = char((str1[idx1] - 'a' + 1)%26 + 'a');
        
        // Matching
        if(str1[idx1] == str2[idx2]  ||  nxtCh == str2[idx2])
            return check(str1, str2, idx1+1, idx2+1);
        
        return check(str1, str2, idx1+1, idx2);
    }
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        
        if(n1 < n2)     return false;
        
        return check(str1, str2, 0, 0);
    }
};