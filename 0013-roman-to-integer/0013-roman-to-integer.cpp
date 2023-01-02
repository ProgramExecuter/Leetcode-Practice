class Solution {
public:
    int romanToInt(string s) {
        // Map the characters with their values
        map<char, int> mp({
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}
            , {'C', 100}, {'D', 500}, {'M', 1000} 
        });
        
        // We keep the previous character's value
        int prev = 0, res = 0;
        
        for(char ch : s) {
            // If the previous char's value < curr's val, then it must have been used to reduce
            if(prev < mp[ch])
                res -= 2 * prev;
            
            res += mp[ch];
            prev = mp[ch];
        }
        
        return res;
    }
};