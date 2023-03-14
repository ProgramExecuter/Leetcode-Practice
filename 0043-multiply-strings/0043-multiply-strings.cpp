class Solution {
public:
    // Do sum of 2 number strings
    void doSum(string &res, string str) {
        string tmp = res;
        int i1 = tmp.size()-1, i2 = str.size()-1;
        res = "";
        
        int carry = 0;
        while(i1 >= 0 or i2 >= 0 or carry > 0) {
            int currNum = carry;
            
            if(i1 >= 0)     currNum += tmp[i1] - '0';
            if(i2 >= 0)     currNum += str[i2] - '0';
            
            res += char('0' + (currNum % 10));
            carry = currNum / 10;
            --i1;       --i2;
        }
        
        reverse(res.begin(), res.end());
    }
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        string res = "0";
        
        if(num1.compare("0") == 0 or num2.compare("0") == 0)
            return res;
        
        for(int i1 = len1-1; i1 >= 0; --i1) {
            string tmp = "";
            
            // Add zeros at end
            for(int x = 0; x < len1-1-i1; ++x)
                tmp += '0';
            
            // Multiply each digit
            int carry = 0;
            for(int i2 = len2-1; i2 >= 0; --i2) {
                int currNum = (num1[i1] - '0') * (num2[i2] - '0') + carry;
                tmp += char('0' + (currNum % 10));
                carry = currNum / 10;
            }
            
            // Add another digit if carry is present
            if(carry)   tmp += char('0' + carry);
            
            // Reverse the number, and sum it with 'res'
            reverse(tmp.begin(), tmp.end());
            doSum(res, tmp);
        }
        
        return res;
    }
};