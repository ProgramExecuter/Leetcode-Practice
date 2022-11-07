class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res;
        multiset<pair<string, string>> st;
        
        for(string s : logs) {
            int i = 0, n = s.size();
            while(s[i] != ' ')
                ++i;
            
            string key = s.substr(0, i);
            string val = s.substr(i+1, n-i-1);
            
            if(val[0] >= '0'  and  val[0] <= '9')
                res.push_back(key + " " + val);
            else
                st.insert({val, key});
        }
        
        reverse(res.begin(), res.end());
        
        for(auto curr = st.rbegin(); curr != st.rend(); ++curr)
            res.push_back(curr->second + " " + curr->first);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};