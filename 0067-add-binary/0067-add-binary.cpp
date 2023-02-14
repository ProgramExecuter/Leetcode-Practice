class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res;
        
        for(int i = a.size()-1, j = b.size()-1; i >= 0  or j >= 0 or carry > 0; --i, --j) {
            int curr = carry;
            
            if(i >= 0  and  a[i] == '1')    ++curr;
            if(j >= 0  and  b[j] == '1')    ++curr;
            
            carry = curr > 1 ? 1 : 0;
            res += char('0' + curr % 2);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};