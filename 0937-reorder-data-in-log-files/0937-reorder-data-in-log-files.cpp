class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        multiset<pair<string, string>> st;
        
        // Iterate all logs
        for(string s : logs) {
            // Split the identifier and string
            int i = 0, n = s.size();
            while(s[i] != ' ')
                ++i;
            
            // Mark them as 'key' and 'val'
            string key = s.substr(0, i);
            string val = s.substr(i+1, n-i-1);
            
            // If this is numerical string
            if(val[0] >= '0'  and  val[0] <= '9')
                res.push_back(key + " " + val);
            // Else insert it to multi-set, for sorting
            else
                st.insert({val, key});
        }
        
        // Reverse the numerical result
        reverse(res.begin(), res.end());
        
        // Start from back
        for(auto curr = st.rbegin(); curr != st.rend(); ++curr)
            res.push_back(curr->second + " " + curr->first);
        
        // Reverse again to get result
        reverse(res.begin(), res.end());
        
        return res;
    }
};