class Solution {
public:
    int getStringVal(string &str) {
        int val = 0;
        
        for(char ch : str) {
            if(ch >= '0' and ch <= '9')
                val = val*10 + (ch-'0');
            else
                return -1;
        }
        
        return val;
    }
    int maximumValue(vector<string>& strs) {
        int maxStringVal = 0;
        
        // Check each String for the maximum value
        for(string str : strs) {
            // Get the value, it return -1, if the string contains any character
            int currStringVal = getStringVal(str);
            
            if(currStringVal == -1)
                currStringVal = str.size();
            
            maxStringVal = max(maxStringVal, currStringVal);
        }
        
        return maxStringVal;
    }
};