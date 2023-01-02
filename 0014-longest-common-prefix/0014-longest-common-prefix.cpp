class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), i = 0;
        
        // Sort the array of strings
        sort(strs.begin(), strs.end());
        
        // Compare the first & last string
        string a = strs[0], b = strs[n-1];
        for(; i < min(a.size(), b.size()); ++i) {
            if(a[i] != b[i])    break;
        }
        
        // Return the common prefix string
        return strs[0].substr(0, i);
    }
};