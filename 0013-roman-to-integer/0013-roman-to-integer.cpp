class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp({
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}
            , {'C', 100}, {'D', 500}, {'M', 1000} 
        });
        
        int prev = 0, res = 0;
        for(char ch : s) {
            if(prev < mp[ch])
                res -= 2 * prev;
            res += mp[ch];
            prev = mp[ch];
        }
        
        return res;
    }
};