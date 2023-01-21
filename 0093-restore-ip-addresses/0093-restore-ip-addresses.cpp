class Solution {
public:
    // Check if we have leading zeros
    bool check(int x, int xInt) {
        return (
            (x == 2  and  xInt < 10)  or
            (x == 3  and  xInt < 100)
        );
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        
        for(int a = 1; a < 4; ++a)
        for(int b = 1; b < 4; ++b)
        for(int c = 1; c < 4; ++c)
        {
            int d = s.size() - a - b - c;
            if(d > 0  and  d < 4)
            {
                string aStr = s.substr(0, a), bStr = s.substr(a, b);
                string cStr = s.substr(a+b, c), dStr = s.substr(a+b+c, d);
                
                int aInt = stoi(aStr), bInt = stoi(bStr);
                int cInt = stoi(cStr), dInt = stoi(dStr);
                
                // If the sections have leading zeros or out-of-range, SKIP
                if(
                    check(a,aInt) or check(b,bInt) or check(c,cInt) or check(d,dInt)
                    or aInt > 255 or bInt > 255 or cInt > 255 or dInt > 255
                )
                    continue;
                
                string curr = aStr + '.' + bStr + '.' + cStr + '.' + dStr;
                res.push_back(curr);
            }
        }
        
        return res;
    }
};