class Solution {
public:
    vector<int> partitionLabels(string s) {
        // For storing last index where a character appears
        vector<int> lastIdx(26, -1);
        int len = s.size();
        
        for(int i = 0; i < len; ++i)
            lastIdx[s[i]-'a'] = i;
        
        vector<int> ans;
        
        int i = 0;
        while(i < len) {
            // Now start and end index of this substring is 'i'
            int st = i, en = i;
            
            // While we reach end of current substring
            while(i <= en) {
                // Check if we need to extend the end index
                en = max(en, lastIdx[s[i]-'a']);
                ++i;
            }
            
            // Push the size of substring in 'ans'
            ans.push_back(en-st+1);
            
            // Move to next substring
            i = en+1;
        }
        
        return ans;
    }
};