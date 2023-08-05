class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string> st;
        int res = 0;
        
        for(string s : words) {
            string orgS = s;
            reverse(s.begin(), s.end());
            
            if(st.find(s) != st.end()) {    st.erase(s);    ++res;  }
            else {  st.insert(orgS); }
        }
        
        return res;
    }
};